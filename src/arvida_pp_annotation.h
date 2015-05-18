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

#ifdef __arvida_parse__

#if 0
#include <stddef.h>
#include <stdint.h>

typedef ssize_t _arvida_ssize_t __attribute__((ext_vector_type(1)));
#define ssize_t _arvida_ssize_t

typedef size_t _arvida_size_t __attribute__((ext_vector_type(1)));
#define size_t _arvida_size_t

typedef int8_t _arvida_int8_t __attribute__((ext_vector_type(1)));
#define int8_t _arvida_int8_t

typedef uint8_t _arvida_uint8_t __attribute__((ext_vector_type(1)));
#define uint8_t _arvida_uint8_t

typedef int16_t _arvida_int16_t __attribute__((ext_vector_type(1)));
#define int16_t _arvida_int16_t

typedef uint16_t _arvida_uint16_t __attribute__((ext_vector_type(1)));
#define uint16_t _arvida_uint16_t

typedef int32_t _arvida_int32_t __attribute__((ext_vector_type(1)));
#define int32_t _arvida_int32_t

typedef uint32_t _arvida_uint32_t __attribute__((ext_vector_type(1)));
#define uint32_t _arvida_uint32_t

typedef int64_t _arvida_int64_t __attribute__((ext_vector_type(1)));
#define int64_t _arvida_int64_t

typedef uint64_t _arvida_uint64_t __attribute__((ext_vector_type(1)));
#define uint64_t _arvida_uint64_t
#endif

#endif

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

// This is a customized macro added into arvida-preprocessor, we use this to distinguish a ARVIDA preprocessor scanning
// from a normal compiling using clang as compiler.
// This can help cut normal compiling time since starting from XCode 4.3, clang has become the official
// compiler on Mac OS X
#ifdef __arvida_parse__


    //
    // Injects a unique structure within the arvida_internal namespace that only the Clang frontend
    // can see so that it can register the specified symbol for reflection.
    // Can only be called from the global namespace and results in the primitive and any children
    // being fully reflected.
    //
    #define arvida_reflect(name)                     \
                                                    \
        namespace arvida_internal                    \
        {                                           \
            struct                                  \
            __attribute__((annotate("full-"#name))) \
            ARVIDA_UNIQUE(cldb_reflect) { };         \
        }


    //
    // Similar to arvida_reflect with the only difference being that the primitive being specified
    // is being partially reflected. Anything that is a child of that primitive has to be
    // explicitly reflected as a result.
    //
    #define arvida_reflect_part(name)                \
                                                    \
        namespace arvida_internal                    \
        {                                           \
            struct                                  \
            __attribute__((annotate("part-"#name))) \
            ARVIDA_UNIQUE(cldb_reflect) { }; \
        }


    //
    // A container must have iterators if you want to use reflection to inspect it. Call this from
    // the global namespace in the neighbourhood of any iterator implementations and it will
    // partially reflect the iterators and allow the parent container to be used with reflection.
    //
    #define arvida_container_iterators(container, read_iterator, write_iterator, keyinfo)                            \
        arvida_reflect_part(read_iterator)                                                                           \
        arvida_reflect_part(write_iterator)                                                                          \
        namespace arvida_internal                                                                                    \
        {                                                                                                           \
            struct                                                                                                  \
            __attribute__((annotate("container-" #container "-" #read_iterator "-" #write_iterator "-" #keyinfo)))  \
            ARVIDA_UNIQUE(container_info) { };                                                               \
        }


    #define arvida_attr(...) __attribute__((annotate("attr:" #__VA_ARGS__)))
    #define arvida_push_attr(...) struct ARVIDA_UNIQUE(push_attr) { } __attribute__((annotate(#__VA_ARGS__)));
    #define arvida_pop_attr(...) struct ARVIDA_UNIQUE(pop_attr) { } __attribute__((annotate(#__VA_ARGS__)));


    //
    // Clang does not need to see these
    //
    #define arvida_impl_class(scoped_type)

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


    //
    // The main compiler does not need to see these
    //
    #define arvida_reflect(name)
    #define arvida_reflect_part(name)
    #define arvida_container_iterators(container, read_iterator, write_iterator, keyinfo)
    #define arvida_attr(...)
    #define arvida_push_attr(...)
    #define arvida_pop_attr(...)


    //
    // Introduces overloaded construction and destruction functions into the ARVIDA::internal
    // namespace for the type you specify. These functions end up in the list of methods
    // in the specified type for easy access.
    // This can only be used from global namespace.
    //
    #define arvida_impl_class(type)                              \
                                                                \
        ARVIDA_API void arvidaConstructObject(type* object)       \
        {                                                       \
            ARVIDA::internal::CallConstructor(object);           \
        }                                                       \
        ARVIDA_API void arvidaDestructObject(type* object)        \
        {                                                       \
            ARVIDA::internal::CallDestructor(object);            \
        }                                                       \


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

#define RdfStmt(a, b, c)                         \
    ArvidaMemberAnnotationBegin("triple")         \
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
#define arvida_declare_func(name, ...)                                                                           \
    ARVIDA_DECL_FUNC_OBJ(name);                                                                                  \
    ARVIDA_BEGIN_EXTERN_C                                                                                        \
    static ARVIDA_Result ARVIDA_JOIN(_kpp_,name)(ARVIDA_FUNC_OBJ(name) arvida_func_object, __VA_ARGS__) { return ARVIDA_SUCCESS; }  \
    ARVIDA_END_EXTERN_C                                                                                          \
    arvida_declare_object(ARVIDA_JOIN(_kpp_,name))
#define arvida_declare_service(name, ...)                                                                        \
    ARVIDA_BEGIN_EXTERN_C                                                                                        \
    static ARVIDA_Result ARVIDA_JOIN(_kpp_,name)(ARVIDA_ServiceFuncObj *arvida_func_object, __VA_ARGS__) { return ARVIDA_SUCCESS; }    \
    ARVIDA_END_EXTERN_C                                                                                          \
    arvida_declare_object(ARVIDA_JOIN(_kpp_,name))

#define arvida_annotate_object(T, ...) _arvida_decls( arvida_reflect_object_ext(T, __VA_ARGS__); )

#define arvida_class_stmt(a, b, c) \
        "arvida-class-stmt", ARVIDA_STRINGIZE(a), ARVIDA_STRINGIZE(b), ARVIDA_STRINGIZE(c), "arvida-eop"

#define arvida_member_stmt(member_name, a, b, c)                           \
        "arvida-member-stmt", #member_name, ARVIDA_STRINGIZE(a), ARVIDA_STRINGIZE(b), ARVIDA_STRINGIZE(c), "arvida-eop"

#define arvida_member_path(member_name, path)                           \
        "arvida-member-path", #member_name, path, "arvida-eop"

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

#define RdfStmt(a, b, c)

#define _arvida_decls(decls)
#define arvida_declare_object(T)
#define arvida_declare_opaque_object(T, ...)
#define arvida_declare_struct(T, ...)
#define arvida_declare_struct_with_api(T, ...)
#define arvida_user_api(api_name, func)
#define arvida_struct_array_member(ptr_type_name, ptr_member_name, size_type_name, size_member_name)
#define arvida_declare_func(name, ...)
#define arvida_declare_service(name, ...)

#define arvida_annotate_object(T, ...)
#define arvida_class_stmt(a, b, c)
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
