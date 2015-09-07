/****************************************************************************/
/* TestFarm Virtual User                                                    */
/* Capture Device - Equipment Interface                                     */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 04-DEC-2007                                                    */
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

#ifndef __TVU_CAPTURE_DEVICE_H__
#define __TVU_CAPTURE_DEVICE_H__

#include "capture_attr.h"


typedef enum {
  CAPTURE_PIXFMT_RGB24=0,
  CAPTURE_PIXFMT_BGR24,
  CAPTURE_PIXFMT_MONO8,
  CAPTURE_PIXFMT_BAYER8,
  CAPTURE_PIXFMT_RGB565,
  CAPTURE_PIXFMT_N
} capture_pixfmt_t;


typedef struct {
  void *base;
  unsigned long length;
  unsigned long bytesused;
  int busy;
} capture_buf_t;


typedef void (*capture_func)(void *ctx);

#define CAPTURE_DEV(_ptr_) ((capture_dev_t *)(_ptr_))

typedef struct {
  char *name;
  char *basename;
  unsigned int width;          /* Full screen width */
  unsigned int height;         /* Full screen height */
  capture_pixfmt_t pixfmt;     /* Pixel format */
  unsigned int pixsize;        /* Pixel size */

  int nbufs;                   /* Streaming buffers pool */
  capture_buf_t *bufs;
  char buf_ready;
} capture_dev_t;


extern void capture_dev_set(capture_dev_t *dev, char *name);
extern void capture_dev_clear(capture_dev_t *dev);


extern capture_dev_t *device_open(char *devname, capture_func callback_func, void *callback_ctx);
extern void device_close(capture_dev_t *dev);

extern int device_attach(capture_dev_t *dev);
extern void device_detach(capture_dev_t *dev);

extern int device_qbuf(capture_dev_t *dev, int index);
extern int device_read(capture_dev_t *dev);

extern int device_attr_set(capture_dev_t *dev, char *key, char *value);
extern capture_attr_t *device_attr_get(capture_dev_t *dev, char *key, int *nmemb);

extern void device_show_status(capture_dev_t *dev, char *hdr);

#endif /* __TVU_CAPTURE_DEVICE_H__ */
