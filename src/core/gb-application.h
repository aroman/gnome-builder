/* gb-application.h
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

#ifndef GB_APPLICATION_H
#define GB_APPLICATION_H

#include <gtk/gtk.h>

#include "gb-service.h"

G_BEGIN_DECLS

#define GB_TYPE_APPLICATION            (gb_application_get_type())
#define GB_APPLICATION_DEFAULT         (gb_application_get_default())
#define GB_APPLICATION(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_APPLICATION, GbApplication))
#define GB_APPLICATION_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_APPLICATION, GbApplication const))
#define GB_APPLICATION_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  GB_TYPE_APPLICATION, GbApplicationClass))
#define GB_IS_APPLICATION(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GB_TYPE_APPLICATION))
#define GB_IS_APPLICATION_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GB_TYPE_APPLICATION))
#define GB_APPLICATION_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  GB_TYPE_APPLICATION, GbApplicationClass))

#define GB_SERVICE_REGISTER(name, lower, TYPE, always_local) \
   static void lower##_register (void) __attribute__((constructor)); \
   static void lower##_register (void) \
   { \
      gb_application_register_service_type(GB_APPLICATION_DEFAULT, \
                                           name, TYPE, always_local); \
   }

typedef struct _GbApplication        GbApplication;
typedef struct _GbApplicationClass   GbApplicationClass;
typedef struct _GbApplicationPrivate GbApplicationPrivate;

struct _GbApplication
{
   GtkApplication parent;

   /*< private >*/
   GbApplicationPrivate *priv;
};

struct _GbApplicationClass
{
   GtkApplicationClass parent_class;
};

GbApplication *gb_application_get_default           (void);
GbService     *gb_application_get_service           (GbApplication *application,
                                                     GType          service_type);
GType          gb_application_get_type              (void) G_GNUC_CONST;
void           gb_application_register_service_type (GbApplication *application,
                                                     const gchar   *name,
                                                     GType          service_type,
                                                     gboolean       always_in_parent);

G_END_DECLS

#endif /* GB_APPLICATION_H */
