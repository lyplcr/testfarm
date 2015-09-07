/****************************************************************************/
/* TestFarm                                                                 */
/* Standard Installation Environment Settings                               */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 08-AUG-2003                                                    */
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

#ifndef __TESTFARM_INSTALL_H__
#define __TESTFARM_INSTALL_H__

#define INSTALL_HOME   "/opt/testfarm"
#define INSTALL_CONFIG "/var/testfarm"
#define INSTALL_DEFAULT_BROWSER "firefox"
#define INSTALL_DEFAULT_PERLDB "ptkdb"
#define INSTALL_LOGVIEW "testfarm-logview"

extern char *get_home(void);
extern char *get_config(void);
extern char *get_font_fixed(void);
extern char *get_browser(void);
extern char *get_perldb(void);

extern char *get_user_config(char *fmt, ...);

extern char *get_lib(char *fname);

#endif /* __TESTFARM_INSTALL_H__ */
