/****************************************************************************/
/* TestFarm Virtual User                                                    */
/* Filter item                                                              */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 29-AUG-2007                                                    */
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

#ifndef __TVU_FILTER_H__
#define __TVU_FILTER_H__

#include <glib.h>

#include "tstamp.h"
#include "frame_hdr.h"


typedef struct filter_s filter_t;

typedef filter_t * (*filter_alloc_func)(char *class_id, GList *options);
typedef void (*filter_destroy_func)(filter_t *filter);
typedef void (*filter_show_func)(filter_t *filter, char *header, char *trailer);
typedef void (*filter_apply_func)(filter_t *filter, frame_hdr_t *frame);

typedef struct {
  char *id;
  filter_alloc_func alloc;
  filter_destroy_func destroy;
  filter_show_func show;
  filter_apply_func apply;
} filter_class_t;

typedef void (*filter_callback_func)(filter_t *filter, void *ctx);

#define FILTER(_ptr_) ((filter_t *)(_ptr_))

struct filter_s {
  filter_class_t *class;
  int index;
  tstamp_t t0;                     /* Processing start time stamp */
  tstamp_t dt;                     /* Processing duration */
  filter_callback_func callback;
  void *ctx;
};


extern void filter_init(void);
extern void filter_done(void);
extern void filter_register(filter_class_t *class);
extern void filter_show_classes(void);

extern filter_t *filter_alloc(char *class_id, GList *options);
extern void filter_destroy(filter_t *filter);

extern void filter_show(filter_t *filter, char *hdr);

extern void filter_set_callback(filter_t *filter, filter_callback_func callback, void *ctx);

extern void filter_apply(filter_t *filter, frame_hdr_t *frame);
extern void filter_applied(filter_t *filter);

#endif /* __TVU_FILTER_H__ */
