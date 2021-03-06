#ifndef DEF_H
#define DEF_H

#include <QString>

#define DELETEPTR(ptr) if(ptr) {delete ptr; ptr = 0;}

#define MOLI_APP_TITLE "交互式磨粒图谱库构建系统"

#define MOLI_IMAGE_FILTER "图像 (*.png *.bmp *.jpg *.jpeg)"

#define MOLI_MESSAGEBOX_TITLE_PROMPT_STRING "提示"

#define MOLI_LABELLED_STATUS_CHAR   "Y"
#define MOLI_UNLABELLED_STATUS_CHAR "N"



#endif // DEF_H
