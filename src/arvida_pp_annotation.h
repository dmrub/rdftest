/*  ARVIDAPP - Arvida C++ Preprocessor
 *
 *  Copyright (C) 2015  German Research Center for Artificial Intelligence (DFKI)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */
#ifndef ARVIDA_PP_ANNOTATION_H_INCLUDED
#define ARVIDA_PP_ANNOTATION_H_INCLUDED

// Macros from Boost C++ Libraries

//
// Helper macro ARVIDA_STRINGIZE:
// Converts the parameter X to a string after macro replacement
// on X has been performed.
//
#define ARVIDA_STRINGIZE(X) ARVIDA_DO_STRINGIZE(X)
#define ARVIDA_DO_STRINGIZE(X) #X

//
// Helper macro ARVIDA_JOIN:
// The following piece of macro magic joins the two
// arguments together, even when one of the arguments is
// itself a macro (see 16.3.1 in C++ standard).  The key
// is that macro expansion of macro arguments does not
// occur in ARVIDA_DO_JOIN2 but does in ARVIDA_DO_JOIN.
//
#define ARVIDA_JOIN( X, Y ) ARVIDA_DO_JOIN( X, Y )
#define ARVIDA_DO_JOIN( X, Y ) ARVIDA_DO_JOIN2(X,Y)
#define ARVIDA_DO_JOIN2( X, Y ) X##Y

#define ARVIDA_UNIQUE(x) ARVIDA_JOIN(x, __COUNTER__)

#ifdef __arvida_parse__

#ifdef __cplusplus
extern "C"
{
#endif

void * arvida_reflect_get_type_ptr(unsigned long);
void   arvida_reflect_object(unsigned long);
void   arvida_reflect_object_ext(unsigned long, ...);

#ifdef __cplusplus
}
#endif


#define arvida_get_reflected_type(T, R)  \
    (R*)arvida_reflect_get_type_ptr(sizeof(T))

#define arvida_reflect_object(T)                \
    arvida_reflect_object(sizeof(T))

#define arvida_reflect_object_ext(T, ...)                \
    arvida_reflect_object_ext(sizeof(T), __VA_ARGS__)

#define arvida_reflect_type(T)                        \
    struct                                           \
    __attribute__((type_tag_for_datatype(arvida, T))) \
    ARVIDA_UNIQUE(arvida_reflect) { };

#else

#define arvida_reflect_object(T)
#define arvida_reflect_type(T)

#endif

#endif

typedef struct ArvidaType ArvidaType;

#ifdef __arvida_parse__
#define arvida_type(T) arvida_get_reflected_type(T, ArvidaType)
#else
#define arvida_type(T) (ArvidaType*)NULL
#endif

#ifdef __arvida_parse__
#define arvida_declare_type(T) arvida_reflect_type(T)
#else
#define arvida_declare_type(T)
#endif

#ifdef __arvida_parse__

#define ARVIDA_UNIQUE_PREFIX(tag) "arvida-" tag "-" ARVIDA_STRINGIZE(__COUNTER__)

#define ArvidaAnnotation(text) __attribute__((annotate(text)))
#define ArvidaMemberAnnotationBegin(tag) __attribute__((annotate( ARVIDA_UNIQUE_PREFIX(tag) )))
#define ArvidaMemberAnnotation(s) __attribute__((annotate( ARVIDA_UNIQUE_PREFIX("param") ":" s)))
#define ArvidaMemberAnnotationEnd() __attribute__((annotate(  ARVIDA_UNIQUE_PREFIX("eop") )))

#define RdfPath(path)  ArvidaMemberAnnotationBegin("path") ArvidaMemberAnnotation(path) ArvidaMemberAnnotationEnd()
#define RdfUseVisitor() ArvidaMemberAnnotationBegin("use-visitor") ArvidaMemberAnnotationEnd()
#define RdfInclude(include) ArvidaMemberAnnotationBegin("include") ArvidaMemberAnnotation(include) ArvidaMemberAnnotationEnd()

#define RdfStmt(a, b, c)                           \
    ArvidaMemberAnnotationBegin("triple")          \
    ArvidaMemberAnnotation(ARVIDA_STRINGIZE(a))    \
    ArvidaMemberAnnotation(ARVIDA_STRINGIZE(b))    \
    ArvidaMemberAnnotation(ARVIDA_STRINGIZE(c))    \
    ArvidaMemberAnnotationEnd()


#define HIDDEN __attribute__((annotate("hidden")))

#define result_value __attribute__((annotate("arvida-result")))

#define _arvida_decls(decls) static void ARVIDA_UNIQUE(arvida_reg)(void) { decls }
#define arvida_declare_object(T) _arvida_decls( arvida_reflect_object(T); )
#define arvida_declare_opaque_object(T, ...) _arvida_decls( arvida_reflect_object_ext(T, "arvida-opaque-object", "arvida-eop", __VA_ARGS__); )
#define arvida_declare_struct(T, ...) _arvida_decls( arvida_reflect_object_ext(T, __VA_ARGS__); )
#define arvida_declare_struct_with_api(T, ...) _arvida_decls( arvida_reflect_object_ext(T, __VA_ARGS__); )
#define arvida_user_api(api_name, func) "arvida-user-api", #api_name, sizeof(func), "arvida-eop"
#define arvida_struct_array_member(ptr_member_name, size_member_name) \
    "arvida-struct-array-member", #ptr_member_name, #size_member_name, "arvida-eop"

#define arvida_annotate_object(T, ...) _arvida_decls( arvida_reflect_object_ext(T, __VA_ARGS__); )

#define arvida_class_stmt(a, b, c) \
        "arvida-class-stmt", ARVIDA_STRINGIZE(a), ARVIDA_STRINGIZE(b), ARVIDA_STRINGIZE(c), "arvida-eop"

#define arvida_member_stmt(member_name, a, b, c)                           \
        "arvida-member-stmt", #member_name, ARVIDA_STRINGIZE(a), ARVIDA_STRINGIZE(b), ARVIDA_STRINGIZE(c), "arvida-eop"

#define arvida_member_path(member_name, path)                           \
        "arvida-member-path", #member_name, path, "arvida-eop"

#define arvida_class_use_visitor() \
        "arvida-class-use-visitor", "arvida-eop"

#define arvida_class_include(include) \
        "arvida-class-include", ARVIDA_STRINGIZE(include), "arvida-eop"

#define arvida_object_semantic(semantic_value) \
            "arvida-object-semantic", semantic_value, "arvida-eop"
#define arvida_field_semantic(field_name, semantic_value) \
            "arvida-field-semantic", #field_name, semantic_value, "arvida-eop"

#define arvida_member_semantic(member_name, semantic_value) \
            "arvida-member-semantic", #member_name, semantic_value, "arvida-eop"

#define arvida_annotate_member(member_name, annotation_name, annotation_value) \
            "arvida-annotate-member", #member_name, #annotation_name, annotation_value, "arvida-eop"

#else

#define HIDDEN

#define ARVIDA_UNIQUE_PREFIX(tag)

#define ArvidaAnnotation(text)
#define ArvidaMemberAnnotationBegin(tag)
#define ArvidaMemberAnnotation(s)
#define ArvidaMemberAnnotationEnd()

#define RdfPath(path)
#define RdfUseVisitor()
#define RdfInclude(include)
#define RdfStmt(a, b, c)

#define _arvida_decls(decls)
#define arvida_declare_object(T)
#define arvida_declare_opaque_object(T, ...)
#define arvida_declare_struct(T, ...)
#define arvida_declare_struct_with_api(T, ...)
#define arvida_user_api(api_name, func)
#define arvida_struct_array_member(ptr_type_name, ptr_member_name, size_type_name, size_member_name)

#define arvida_annotate_object(T, ...)
#define arvida_class_stmt(a, b, c)
#define arvida_class_use_visitor()
#define arvida_class_include(include)
#define arvida_member_stmt(member_name, a, b, c)
#define arvida_member_path(member_name, path)

#define arvida_field_semantic(field_name, semantic_value)
#define arvida_member_semantic(member_name, semantic_value)
#define arvida_annotate_member(member_name, annotation_name, annotation_value)

#endif

#define rdf_annotate_object(T, ...) arvida_annotate_object(T, __VA_ARGS__)
#define rdf_class_stmt(a, b, c) arvida_class_stmt(a, b, c)
#define rdf_member_stmt(member_name, a, b, c) arvida_member_stmt(member_name, a, b, c)
#define rdf_member_path(member_name, path) arvida_member_path(member_name, path)
