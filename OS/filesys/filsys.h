#ifndef FILSYS_H
#define FILSYS_H

#endif // FILSYS_H

struct  filsys
{
 unsigned short     s_isize;        /* inode�� */
 unsigned short     s_fsize;        /* ������� */
 unsigned short     s_nfree;        /* ���п��� */
 unsigned short     s_free[200];    /* ���п飨0~200�� */
 unsigned short     s_ninode;       /* ����inode�� */
 unsigned short     s_inode[200];   /* ����inode(0~200) */
};
