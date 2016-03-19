///////////////////////////////////////////////////////////////////////////////
// Copyright (c) Electronic Arts Inc. All rights reserved.
///////////////////////////////////////////////////////////////////////////////


#ifndef EASTL_FORWARDLIST_H
#define EASTL_FORWARDLIST_H


#include <EASTL/internal/config.h>
#include <EASTL/allocator.h>
#include <EASTL/type_traits.h>
#include <EASTL/iterator.h>
#include <EASTL/algorithm.h>
#include <EASTL/initializer_list.h>
#include <EASTL/sort.h>
#include <EASTL/slist.h>
#include <stddef.h>


#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once 
#endif

namespace eastl
{
    #if defined(EA_COMPILER_NO_TEMPLATE_ALIASES)
        template <typename T, typename Allocator = EASTLAllocatorType>
        class forward_list : public slist<T, Allocator> 
        {
            typedef slist<T, Allocator> base_type;
            typedef forward_list<T, Allocator> this_type;

        public:
            using base_type::value_type;
            using base_type::iterator;
            using base_type::const_iterator;
            using base_type::size_type;
            using base_type::difference_type;
            using base_type::allocator_type;
            using base_type::node_type;
            using base_type::base_node_type;

            using base_type::pointer;
            using base_type::const_pointer;
            using base_type::reference;
            using base_type::const_reference;
            
        public:
            this_type() : base_type() {}
            this_type(const allocator_type& allocator) : base_type(allocator_type) {}
            explicit this_type(size_type n, const allocator_type& allocator = EASTL_SLIST_DEFAULT_ALLOCATOR) : base_type(n, allocator) {}
            this_type(size_type n, const value_type& value, const allocator_type& allocator = EASTL_SLIST_DEFAULT_ALLOCATOR) : base_type(n, value, allocator) {}
            this_type(const this_type& x) : base_type(x) {}
            this_type(std::initializer_list<value_type> ilist, const allocator_type& allocator = EASTL_SLIST_DEFAULT_ALLOCATOR) : base_type(ilist, allocator) {}
            template <typename InputIterator>
            this_type(InputIterator first, InputIterator last) : base_type(first, last) {}
            #if EASTL_MOVE_SEMANTICS_ENABLED
                this_type(this_type&& x) : base_type(eastl::move(x)) {}
                this_type(this_type&& x, const allocator_type& allocator) : base_type(eastl::move(x), allocator) {}
            #endif

            using base_type::swap;
            using base_type::assign;
            using base_type::begin;
            using base_type::cbegin;
            using base_type::end;
            using base_type::cend;
            using base_type::before_begin;
            using base_type::cbefore_begin;
            using base_type::previous;
            using base_type::front;
        };
    #else
        template <typename T, typename Allocator = EASTLAllocatorType>
        using forward_list = slist<T, Allocator>;
    #endif
} // namespace eastl


#endif // Header include guard























