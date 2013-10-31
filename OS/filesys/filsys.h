#ifndef FILSYS_H
#define FILSYS_H

#endif // FILSYS_H

struct  filsys
{
 unsigned short     s_isize;        /* inode数 */
 unsigned short     s_fsize;        /* 最大容量 */
 unsigned short     s_nfree;        /* 空闲块数 */
 unsigned short     s_free[200];    /* 空闲块（0~200） */
 unsigned short     s_ninode;       /* 空闲inode数 */
 unsigned short     s_inode[200];   /* 空闲inode(0~200) */
};
