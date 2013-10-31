#ifndef INODE_H
#define INODE_H

#endif // INODE_H

struct  inode
{
unsigned short     i_mode;
unsigned short     i_size;
unsigned short     i_addr[8];      /* device addresses constituting file */
};

#define IREAD   2
#define IWRITE  1
#define IDIR    4
#define IFILE   8
#define IDELETE 16;
