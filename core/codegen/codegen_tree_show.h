/****************************************************************************/
/* TestFarm                                                                 */
/* Test Suite code generator : Test Tree structure display                  */
/****************************************************************************/
/* Author: Sylvain Giroudon                                                 */
/* Creation: 12-NOV-2006                                                    */
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

#ifndef __TESTFARM_CODEGEN_TREE_SHOW_H
#define __TESTFARM_CODEGEN_TREE_SHOW_H

/*================= TREE OBJECT =========================*/
extern void tree_object_show(tree_object_t *tobject, FILE *f);

/*================= TREE ITEM =========================*/
extern void tree_item_show_name(tree_item_t *item, FILE *f);
extern void tree_item_show(tree_item_t *item, FILE *f);

/*================= TREE =========================*/
extern void tree_show(tree_t *tree, FILE *f);

#endif /* __TESTFARM_CODEGEN_TREE_SHOW_H */
