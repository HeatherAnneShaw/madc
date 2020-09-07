////////////////////////////////////////////////////////////////////////////////
// THE SCOTCH-WARE LICENSE (Revision 0):
// <aaronryool@gmail.com> wrote this file. As long as you retain this notice you
// can do whatever you want with this stuff. If we meet some day, and you think
// this stuff is worth it, you can buy me a shot of scotch in return
////////////////////////////////////////////////////////////////////////////////

#ifndef __config_h__
#define __config_h__ 1


extern int line_number;
extern int col_number;
#define LC_UPDATE col_number = columno();line_number = lineno();


#define MAX_INCLUDE_DEPTH 99

// if you want debugging set this to true
#define __debug__ false

#endif
