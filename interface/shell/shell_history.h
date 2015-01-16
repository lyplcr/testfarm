/****************************************************************************/
/* TestFarm                                                                 */
/* Shell command history                                                    */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 03-MAY-2010                                                    */
/****************************************************************************/

/*
 * $Revision: 1182 $
 * $Date: 2010-07-11 18:22:26 +0200 (dim., 11 juil. 2010) $
 */

#ifndef __SHELL_HISTORY_H__
#define __SHELL_HISTORY_H__

#include <glib.h>

#define SHELL_HISTORY_MAX 100

typedef struct {
	int id;
	char *str;
	int ret;
} shell_history_item_t;


typedef enum {
	SHELL_HISTORY_ADD,
	SHELL_HISTORY_DEL,
	SHELL_HISTORY_MOVE_UP,
} shell_history_event_t;

typedef void shell_history_callback_t(shell_history_item_t *hsti, shell_history_event_t event, void *data);

typedef struct {
	int count;
	shell_history_item_t tab[SHELL_HISTORY_MAX];
	int id;
	GList *list;
	shell_history_callback_t *callback_func;
	void *callback_data;
} shell_history_t;

extern void shell_history_init(shell_history_t *hst);
extern void shell_history_set_callback(shell_history_t *hst, shell_history_callback_t *func, void *data);

extern shell_history_item_t *shell_history_update(shell_history_t *hst, char *str);
extern void shell_history_first(shell_history_t *hst, shell_history_item_t *item);
extern shell_history_item_t *shell_history_get(shell_history_t *hst, int id);

extern void shell_history_foreach(shell_history_t *hst, void (*func)(shell_history_item_t *item, void *data), void *data);

#endif /* __SHELL_HISTORY_H__ */
