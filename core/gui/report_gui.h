/****************************************************************************/
/* TestFarm                                                                 */
/* Graphical User Interface : Test Report Management                        */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 18-MAY-2000                                                    */
/****************************************************************************/

/*
    This file is part of TestFarm,
    the Test Automation Tool for Embedded Software.
    Please visit http://www.testfarm.org.

    TestFarm is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    TestFarm is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with TestFarm.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef __TESTFARM_REPORT_GUI_H__
#define __TESTFARM_REPORT_GUI_H__

#include <gtk/gtk.h>
#include "child.h"
#include "output.h"
#include "xpm_gui.h"


typedef void report_gui_spot_tree_t(void *user_data, unsigned long key);


typedef struct {
  GtkWidget *window;
  GtkTreeView *view;
  GtkListStore *model;
  GtkTreeModel *model_sort;
  GtkWidget *spot_tree;
  GtkWidget *spot_log;
  unsigned long select_key;
  char *select_name;
} report_gui_list_t;


typedef struct {
  child_t *child;
  int stdin;
} report_gui_proc_t;


typedef struct {
  GtkWidget *window;
  GtkWidget *total;
  GtkWidget *significant;
  GtkWidget *executed;
  GtkWidget *passed;
  GtkWidget *failed;
  GtkWidget *inconclusive;
  GtkWidget *skip;
  GtkWidget *button_list[2];
  GtkWidget *log, *log2;
  GtkWidget *rtv_build;
  GtkWidget *rtv_view, *rtv_view2;

  tree_t *tree;
  output_t *out;

  report_gui_list_t list;

  char *report_name;
  char *log_name;
  report_gui_proc_t log_viewer;
  report_gui_proc_t report_conf;

  report_gui_spot_tree_t *spot_tree_func;
  void *spot_tree_arg;

  int child_pipe[2];
  int child_input;

  child_t *builder;
  int build_then_browse;
} report_gui_t;


extern report_gui_t *report_gui_init(GtkWidget *window,
                                     report_gui_spot_tree_t *spot_tree, void *spot_tree_arg);
extern void report_gui_destroy(report_gui_t *rg);

extern void report_gui_set_name(report_gui_t *rg, char *log_name, char *report_directory);
extern void report_gui_load(report_gui_t *rg, tree_t *tree, output_t *out);
extern void report_gui_unload(report_gui_t *rg);
extern void report_gui_reset(report_gui_t *rg);
extern void report_gui_executed(report_gui_t *rg, unsigned long key, tree_result_t *result);
extern void report_gui_log_show(report_gui_t *rg, char *nodename);

extern GdkPixbuf *report_gui_verdict_pixbuf(int verdict);

#endif /* __TESTFARM_REPORT_GUI_H__ */
