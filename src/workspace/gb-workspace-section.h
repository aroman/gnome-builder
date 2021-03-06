/* gb-workspace-section.h
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

#ifndef GB_WORKSPACE_SECTION_H
#define GB_WORKSPACE_SECTION_H

#include <gtk/gtk.h>

#include "gb-project.h"

G_BEGIN_DECLS

#define GB_TYPE_WORKSPACE_SECTION            (gb_workspace_section_get_type())
#define GB_WORKSPACE_SECTION(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_WORKSPACE_SECTION, GbWorkspaceSection))
#define GB_WORKSPACE_SECTION_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_WORKSPACE_SECTION, GbWorkspaceSection const))
#define GB_WORKSPACE_SECTION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  GB_TYPE_WORKSPACE_SECTION, GbWorkspaceSectionClass))
#define GB_IS_WORKSPACE_SECTION(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GB_TYPE_WORKSPACE_SECTION))
#define GB_IS_WORKSPACE_SECTION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GB_TYPE_WORKSPACE_SECTION))
#define GB_WORKSPACE_SECTION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  GB_TYPE_WORKSPACE_SECTION, GbWorkspaceSectionClass))

typedef struct _GbWorkspaceSection        GbWorkspaceSection;
typedef struct _GbWorkspaceSectionClass   GbWorkspaceSectionClass;
typedef struct _GbWorkspaceSectionPrivate GbWorkspaceSectionPrivate;

struct _GbWorkspaceSection
{
   GtkBin parent;

   /*< private >*/
   GbWorkspaceSectionPrivate *priv;
};

struct _GbWorkspaceSectionClass
{
   GtkBinClass parent_class;

   void          (*set_project)  (GbWorkspaceSection *section,
                                  GbProject          *project);
   GActionGroup *(*get_actions)  (GbWorkspaceSection *section);
};

GType         gb_workspace_section_get_type    (void) G_GNUC_CONST;
void          gb_workspace_section_set_project (GbWorkspaceSection *section,
                                                GbProject          *project);
GActionGroup *gb_workspace_section_get_actions (GbWorkspaceSection *section);

G_END_DECLS

#endif /* GB_WORKSPACE_SECTION_H */
