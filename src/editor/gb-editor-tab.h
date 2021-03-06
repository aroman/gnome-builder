/* gb-editor-tab.h
 *
 * Copyright (C) 2013 Christian Hergert <christian@hergert.me>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GB_EDITOR_TAB_H
#define GB_EDITOR_TAB_H

#include "gb-tab.h"

G_BEGIN_DECLS

#define GB_TYPE_EDITOR_TAB            (gb_editor_tab_get_type())
#define GB_EDITOR_TAB(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_EDITOR_TAB, GbEditorTab))
#define GB_EDITOR_TAB_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_EDITOR_TAB, GbEditorTab const))
#define GB_EDITOR_TAB_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  GB_TYPE_EDITOR_TAB, GbEditorTabClass))
#define GB_IS_EDITOR_TAB(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GB_TYPE_EDITOR_TAB))
#define GB_IS_EDITOR_TAB_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GB_TYPE_EDITOR_TAB))
#define GB_EDITOR_TAB_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  GB_TYPE_EDITOR_TAB, GbEditorTabClass))

typedef struct _GbEditorTab        GbEditorTab;
typedef struct _GbEditorTabClass   GbEditorTabClass;
typedef struct _GbEditorTabPrivate GbEditorTabPrivate;

struct _GbEditorTab
{
   GbTab parent;

   /*< private >*/
   GbEditorTabPrivate *priv;
};

struct _GbEditorTabClass
{
   GbTabClass parent_class;
};

gboolean   gb_editor_tab_get_is_empty (GbEditorTab *tab);
GFile     *gb_editor_tab_get_file     (GbEditorTab *tab);
void       gb_editor_tab_set_file     (GbEditorTab *tab,
                                       GFile       *file);
GType      gb_editor_tab_get_type     (void) G_GNUC_CONST;
GtkWidget *gb_editor_tab_new          (void);
void       gb_editor_tab_find         (GbEditorTab *tab);
void       gb_editor_tab_open         (GbEditorTab *tab,
                                       GFile       *file);
void       gb_editor_tab_save         (GbEditorTab *tab);
void       gb_editor_tab_save_as      (GbEditorTab *tab);

G_END_DECLS

#endif /* GB_EDITOR_TAB_H */
