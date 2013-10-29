/* gb-command-dbus.h
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

#ifndef GB_COMMAND_DBUS_H
#define GB_COMMAND_DBUS_H

#include <gio/gio.h>

#include "gb-command.h"

G_BEGIN_DECLS

#define GB_TYPE_COMMAND_DBUS            (gb_command_dbus_get_type())
#define GB_COMMAND_DBUS(obj)            (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_COMMAND_DBUS, GbCommandDbus))
#define GB_COMMAND_DBUS_CONST(obj)      (G_TYPE_CHECK_INSTANCE_CAST ((obj), GB_TYPE_COMMAND_DBUS, GbCommandDbus const))
#define GB_COMMAND_DBUS_CLASS(klass)    (G_TYPE_CHECK_CLASS_CAST ((klass),  GB_TYPE_COMMAND_DBUS, GbCommandDbusClass))
#define GB_IS_COMMAND_DBUS(obj)         (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GB_TYPE_COMMAND_DBUS))
#define GB_IS_COMMAND_DBUS_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE ((klass),  GB_TYPE_COMMAND_DBUS))
#define GB_COMMAND_DBUS_GET_CLASS(obj)  (G_TYPE_INSTANCE_GET_CLASS ((obj),  GB_TYPE_COMMAND_DBUS, GbCommandDbusClass))

typedef struct _GbCommandDbus        GbCommandDbus;
typedef struct _GbCommandDbusClass   GbCommandDbusClass;
typedef struct _GbCommandDbusPrivate GbCommandDbusPrivate;

struct _GbCommandDbus
{
   GbCommand parent;

   /*< private >*/
   GbCommandDbusPrivate *priv;
};

struct _GbCommandDbusClass
{
   GbCommandClass parent_class;
};

GType      gb_command_dbus_get_type (void) G_GNUC_CONST;
GbCommand *gb_command_dbus_new      (GDBusConnection *connection,
                                     const gchar     *name,
                                     const gchar     *path,
                                     const gchar     *method,
                                     GVariant        *params);

G_END_DECLS

#endif /* GB_COMMAND_DBUS_H */