#ifndef PUBLIC_H
#define PUBLIC_H

#include <QApplication>
#include <QMainWindow>
#include <QPainter>
#include <QPoint>
#include <QPointF>
#include <QColor>
#include <QtGlobal>
#include <QTime>
#include <QTimer>
#include <QKeyEvent>
#include <Qt>

#define HRZ_CENTER 0
#define HRZ_START 1
#define VRTX_CENTER 0
#define VRTX_START 1

#define NUM_OF_BOARDS 2
#define MAIN_BOARD 0
#define NEXT_BOARD 1
#define MAIN_BOARD_WIDTH 16
#define MAIN_BOARD_HEIGHT 34
#define NEXT_BOARD_WIDTH 6
#define NEXT_BOARD_HEIGHT 7
#define CELL_LENGTH 20

#define UP -1
#define DOWN 1
#define LEFT -1
#define RIGHT 1
#define NO_MOVE 0

#define NO_COLOR 0
#define RED 1
#define YELLOW 2
#define BLUE 3
#define GRAY 4
#define BLACK 5
#define PURPLE 6
#define ORANGE 7

#define NUM_OF_SHAPES 7
#define O_SHAPE 0
#define S_SHAPE 1
#define Z_SHAPE 2
#define T_SHAPE 3
#define I_SHAPE 4
#define J_SHAPE 5
#define L_SHAPE 6


#endif // PUBLIC_H
