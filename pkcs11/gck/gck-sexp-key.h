/*
 * gnome-sexp_keyring
 *
 * Copyright (C) 2008 Stefan Walter
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General  License as
 * published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General  License for more details.
 *
 * You should have received a copy of the GNU Lesser General
 * License along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 * 02111-1307, USA.
 */

#ifndef __GCK_SEXP_KEY_H__
#define __GCK_SEXP_KEY_H__

#include <glib-object.h>

#include "gck-sexp.h"
#include "gck-object.h"
#include "gck-types.h"

#define GCK_TYPE_SEXP_KEY               (gck_sexp_key_get_type ())
#define GCK_SEXP_KEY(obj)               (G_TYPE_CHECK_INSTANCE_CAST ((obj), GCK_TYPE_SEXP_KEY, GckSexpKey))
#define GCK_SEXP_KEY_CLASS(klass)       (G_TYPE_CHECK_CLASS_CAST ((klass), GCK_TYPE_SEXP_KEY, GckSexpKeyClass))
#define GCK_IS_SEXP_KEY(obj)            (G_TYPE_CHECK_INSTANCE_TYPE ((obj), GCK_TYPE_SEXP_KEY))
#define GCK_IS_SEXP_KEY_CLASS(klass)    (G_TYPE_CHECK_CLASS_TYPE ((klass), GCK_TYPE_SEXP_KEY))
#define GCK_SEXP_KEY_GET_CLASS(obj)     (G_TYPE_INSTANCE_GET_CLASS ((obj), GCK_TYPE_SEXP_KEY, GckSexpKeyClass))

typedef struct _GckSexpKeyClass GckSexpKeyClass;
typedef struct _GckSexpKeyPrivate GckSexpKeyPrivate;

struct _GckSexpKey {
	GckObject parent;
	GckSexpKeyPrivate *pv;
};

struct _GckSexpKeyClass {
	GckObjectClass parent_class;

	/* virtual methods */

	GckSexp* (*acquire_crypto_sexp) (GckSexpKey *self, GckSession *session);
};

GType                gck_sexp_key_get_type                (void);

GckSexp*             gck_sexp_key_get_base                (GckSexpKey *self);

void                 gck_sexp_key_set_base                (GckSexpKey *self,
                                                           GckSexp *sexp);

int                  gck_sexp_key_get_algorithm           (GckSexpKey *self);

CK_RV                gck_sexp_key_set_part                (GckSexpKey *self,
                                                           int algorithm,
                                                           const char *part,
                                                           CK_ATTRIBUTE_PTR attr);

GckSexp*             gck_sexp_key_acquire_crypto_sexp     (GckSexpKey *self,
                                                           GckSession *session);

#endif /* __GCK_SEXP_KEY_H__ */