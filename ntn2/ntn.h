/*
** ntn.h for ntn in /u/all/sundas_c/cu/rendu/unix/projet/ntn
** 
** Made by christophe sundas
** Login   <sundas_c@epitech.net>
** 
** Started on  Fri Dec  5 20:50:46 2008 christophe sundas
** Last update Sun Dec  7 22:26:54 2008 christophe sundas
*/

extern char	*tab_unit_val[];
extern char	*tab_unit_vals[];
extern char	*tab_unit[];
extern char	*tab_dizaine[];
extern char	*tab_unit_val_en[];
extern char	*tab_unit_en[];
extern char	*tab_dizaine_en[];
extern char	*tab_unit_val_vocfr[];
extern char	*tab_unit_vocfr[];
extern char	*tab_dizaine_vocfr[];
extern char	*tab_min[];

#define SIZEUNITVAL 4
#define SIZEUNIT 20
#define SIZEDIZAINE 10

void	ntn(int ac, char **av);
void	vocal_mode(char *str, int tabopt[]);
void	eng_mode(char *str, int tabopt[]);
void	fr_mode(char *str , int tabopt[]);


/*
** validation
*/

char	*parse_op(char *str);
int	check_valid0(char *str);
int	check_valid(char *str);
int	is_num(char c);
char	*epur_zero(char *str);
int	is_anumber(char *str);
int	is_integer(char *str);

/*
** tranches
*/
t_list	*display_tranches(char *str);
t_list	*display_tranches_en(char *str);
int	nb_to_take(char *str);
void	mk_bloc(char *str, char tabstr[3], int blocsize);
void	display_unit_val(char *str,  t_list **my_list);
void	display_unit_val_en(char *str,  t_list **my_list);
void	display_unit_val_vocfr(char *str);

/*
** bloc de 3
*/
void	display_bloc(char *str, t_list **my_list);
void	display_bloc_en(char *str, t_list **my_list);
void	display_bloc_vocfr(char *str);

/*
** display_cent
*/
void	display_centaine(char *str, t_list **my_list);
void	display_centaine_en(char *str, t_list **my_list);
void	display_centaine_vocfr(char *str);
void	display_plural_cent(char *str, t_list **my_list);

/*
**
*/
int	display_dizaine(char *str, t_list **my_list);
int	display_dizaine_en(char *str, t_list **my_list);
int	display_dizaine_vocfr(char *str);
int	display_sep(char *str, t_list **my_list);

/*
** generic list
*/
void	my_free_list(t_list **begin);
void	my_put_in_list2(t_list **begin, char *data);
void	my_display_list(t_list *list);
void	my_display_list_with_opt(t_list *list, int tabopt[]);
t_list	*remove_at(t_list **begin, int indice, int *cpt);

/*
** Affine liste.h
*/
void	affine_list(t_list **begin);
int	is_unitval_variable(char *str);
int	is_multiplicate(char *num);
char	*find_at(t_list **my_list, int indice);
void	epur_list(t_list **my_list);

/*
** Affine cents, rajoute les s a cent
*/
void	affine_cents(t_list **my_list);
int	is_alone_cent(t_list *begin);

/*
** Affine unit_val
*/
void	affine_unit_val(t_list **my_list);
int	is_plurial(char *str);
int	is_in_tabunit_val(char *str);
int	is_in_tabunit(char *str);
int	is_in_tab_dizaine(char *str);

/*
**
*/
void	display_unit(char *str, t_list **my_list);
void	display_unit_en(char *str, t_list **my_list);
void	display_unit_vocfr(char *str);

/*
** Affine mille
*/
void	affine_mille(t_list **my_list);
int     are_close_un_mil(t_list *begin);
int	need_to_affine_mil(char *str);

/*
** options.h rempli le tab opt
*/
#define BIG_M 0
#define BIG_A 1
#define LITTLE_A 2
#define LANG 3

/*
** valeur de tab langue, fr 0, eng 1, romain2, vocal 3
*/
#define FR 0
#define ENG 1
#define ROMAIN 2
#define VOCAL 3

/*
**upper.c
*/
char	char_to_upper(char c);
char	*str_to_upper(char *str);
char	*str_altern_upper(char *str, int begin, int freq);
int	check_option(int ac, char **av, int tabopt[5]);
int	is_option(char *str, int tabopt[5]);
int	is_valid_option(char c);
void	my_aff_tabopt(int tabopt[5]);
void	player(char *str);
