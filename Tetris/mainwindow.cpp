#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ge = new gameEngine(ui->frm_main->x(), ui->frm_main->y(), ui->frm_next->x(), ui->frm_next->y());
    timer = new QTimer();
    timer->setInterval(150);
    connect(ui->btn_start, SIGNAL(clicked(bool)), this, SLOT(start_game()));
    connect(timer, SIGNAL(timeout()), this, SLOT(timer_start()));
    connect(ui->btn_new, SIGNAL(clicked(bool)), this, SLOT(new_game()));
    setFocusPolicy(Qt::StrongFocus);
    game_is_started = false;
}

void MainWindow::keyReleaseEvent(QKeyEvent* event)
{
    int key = event->key();

    if(game_is_started)
    {
        switch (key)
        {
        case Qt::Key_Down:
            timer->setInterval(150);
            break;

        case Qt::Key_Up:
            if(ge->GetAbleDown())
            {
                ge->rotate();
                update();
            }
            break;

        default:
            break;
        }
    }
}

void MainWindow::keyPressEvent(QKeyEvent * event)
{
    if(ge->GetAbleDown() && game_is_started)
    {
        int key = event->key();

        switch (key)
        {
        case Qt::Key_Left:
            ge->MoveLeft();
            break;

        case Qt::Key_Right:
            ge->MoveRight();
            break;

        case Qt::Key_Down:
            if(timer->interval() != 50)
                timer->setInterval(50);//按下dowm键加速
            break;

        default:
            break;
        }
    }

    update();
}

void MainWindow::paintEvent(QPaintEvent *)
{
    int h = MAIN_BOARD_HEIGHT;
    int w = MAIN_BOARD_WIDTH;

    QPainter painter(this);

    for(int n = 0; n < NUM_OF_BOARDS; n++)
    {
        h = (n == MAIN_BOARD ? h : NEXT_BOARD_HEIGHT);
        w = (n == MAIN_BOARD ? w : NEXT_BOARD_WIDTH);

        for(int r = 0; r < h; r++)
        {
            for(int c = 0; c < w; c++)
            {
                //Draw a rectangle in the cell
                cell acell = (n == NEXT_BOARD ? ge->GetNextBoard().getcell(r, c) : ge->GetMainBoard().getcell(r, c));
                QPointF position = acell.get_position();
                QSizeF sizef(CELL_LENGTH, CELL_LENGTH);
                QRectF rectf(position, sizef);
                QColor color = acell.DrawColor();
                painter.fillRect(rectf, color);
            }
        }
    }
}

void MainWindow::timer_start()
{
    if(ge->GetAbleDown())
    {
        ge->MoveDown();
    }
    else
    {
        if(ge->num_rows_cld() > 0)
        {
            int score = ge->Score();
            score += ui->lbl_score->text().toInt();
            ge->ClearRows();
            ge->rows_move_down();
            ui->lbl_score->setText(QString::number(score));
        }
        ge->PlaceShapeMain();
        ge->GetNextBoard().clearboard();
        ge->PlaceShapeNext();
    }
    update();
}

void MainWindow::start_game()
{
    ge->PlaceShapeNext();
    ge->PlaceShapeMain();
    ge->GetNextBoard().clearboard();
    ge->PlaceShapeNext();
    update();
    ui->btn_start->setEnabled(false);
    timer->start();
    game_is_started = true;
}

void MainWindow::new_game()
{
    game_is_started = false;
    timer->stop();

    delete ge;
    ge = NULL;

    ge = new gameEngine(ui->frm_main->x(), ui->frm_main->y(), ui->frm_next->x(), ui->frm_next->y());

    ui->lbl_score->setText("0");
    ui->btn_start->setEnabled(true);

    update();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ge;
    ui = NULL;
    ge = NULL;
}
