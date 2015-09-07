/****************************************************************************/
/* TestFarm Virtual User                                                    */
/* Display Tool - Pixbufs and Icons                                         */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 08-JAN-2004                                                    */
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

#ifndef __TVU_DISPLAY_XPM_H__
#define __TVU_DISPLAY_XPM_H__

#include <gtk/gtk.h>

extern GdkPixbuf *pixbuf_blank;
extern GdkPixbuf *pixbuf_connect_creating;
extern GdkPixbuf *pixbuf_connect_established;
extern GdkPixbuf *pixbuf_connect_no;

extern GdkPixbuf *pixbuf_frame;

extern void xpm_init(GtkWidget *window);
extern void xpm_done(void);

#endif /* __TVU_DISPLAY_XPM_H__ */
