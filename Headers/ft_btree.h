#ifndef	__FT_BTREE_H__
# define	__FT_BTREE_H__

typedef struct		s_btree 
{
 struct s_btree		*left;
 struct s_btree		*right;
 void				*item; 
}					t_btree;

#endif