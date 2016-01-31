#-------------------------------------------------
#
# Project created by QtCreator 2016-01-31T16:20:34
#
#-------------------------------------------------

QT       += core gui
QMAKE_CXXFLAGS += -std=c++14

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = wiki-editor
TEMPLATE = app


SOURCES += main.cpp\
        editor.cpp \
    component_builder.cpp \
    wiki-client/rest/client.cpp \
    wiki-client/rest/io_service_provider.cpp \
    wiki-client/rest/request.cpp \
    wiki-client/rest/response_header.cpp \
    wiki-markup/components/list/list_type.cpp \
    wiki-markup/components/parsers/basic.cpp \
    wiki-markup/components/parsers/format.cpp \
    wiki-markup/components/post_processors/link.cpp \
    wiki-markup/components/post_processors/list.cpp \
    wiki-markup/components/post_processors/table.cpp \
    wiki-markup/components/comments.cpp \
    wiki-markup/components/header.cpp \
    wiki-markup/components/horizontal_line.cpp \
    wiki-markup/components/link.cpp \
    wiki-markup/components/list.cpp \
    wiki-markup/components/meta_info.cpp \
    wiki-markup/components/preformatted_text.cpp \
    wiki-markup/components/table.cpp \
    wiki-markup/components/text.cpp \
    wiki-markup/components/url.cpp \
    wiki-markup/parser/context_navigation.cpp \
    wiki-markup/parser/page_parser.cpp \
    wiki-markup/parser/parser_context.cpp \
    wiki-markup/parser/token.cpp \
    wiki-markup/parser/token_classification.cpp \
    wiki-markup/configuration.cpp \
    wiki-markup/page.cpp \
    SimpleJSON/parse/jsd_fundamental.cpp \
    SimpleJSON/parse/jsd_generic_parser.cpp \
    SimpleJSON/parse/jsd_options.cpp \
    SimpleJSON/parse/jsd_string.cpp \
    SimpleJSON/stringify/jss_error.cpp \
    SimpleJSON/stringify/jss_fundamental.cpp \
    SimpleJSON/stringify/jss_object.cpp \
    SimpleJSON/stringify/jss_options.cpp \
    SimpleJSON/stringify/jss_pointer.cpp \
    SimpleJSON/stringify/jss_string.cpp \
    SimpleJSON/stringify/jss_void.cpp \
    SimpleJSON/utility/base64.cpp \
    SimpleJSON/utility/beauty_stream.cpp \
    SimpleJSON/utility/xml_converter.cpp \
    SimpleJSON/test.cpp

HEADERS  += editor.h \
    component_builder.h \
    wiki-client/rest/client.hpp \
    wiki-client/rest/io_service_provider.hpp \
    wiki-client/rest/query.hpp \
    wiki-client/rest/request.hpp \
    wiki-client/rest/response_header.hpp \
    wiki-markup/components/list/list_type.hpp \
    wiki-markup/components/parsers/uri/authority.hpp \
    wiki-markup/components/parsers/uri/domain.hpp \
    wiki-markup/components/parsers/uri/domain_name.hpp \
    wiki-markup/components/parsers/uri/ipv4.hpp \
    wiki-markup/components/parsers/uri/ipv6.hpp \
    wiki-markup/components/parsers/uri/scheme.hpp \
    wiki-markup/components/parsers/basic.hpp \
    wiki-markup/components/parsers/comments.hpp \
    wiki-markup/components/parsers/format.hpp \
    wiki-markup/components/parsers/fusion_includes.hpp \
    wiki-markup/components/parsers/header.hpp \
    wiki-markup/components/parsers/indents.hpp \
    wiki-markup/components/parsers/link.hpp \
    wiki-markup/components/parsers/list.hpp \
    wiki-markup/components/parsers/parse.hpp \
    wiki-markup/components/parsers/parser_core.hpp \
    wiki-markup/components/parsers/parsing_results.hpp \
    wiki-markup/components/parsers/phoenix_includes.hpp \
    wiki-markup/components/parsers/properties.hpp \
    wiki-markup/components/parsers/qi_includes.hpp \
    wiki-markup/components/parsers/space.hpp \
    wiki-markup/components/parsers/table.hpp \
    wiki-markup/components/parsers/unescaped_string.hpp \
    wiki-markup/components/parsers/url.hpp \
    wiki-markup/components/post_processors/link.hpp \
    wiki-markup/components/post_processors/list.hpp \
    wiki-markup/components/post_processors/table.hpp \
    wiki-markup/components/table/table_caption.hpp \
    wiki-markup/components/table/table_cell.hpp \
    wiki-markup/components/table/table_row.hpp \
    wiki-markup/components/adaption.hpp \
    wiki-markup/components/comments.hpp \
    wiki-markup/components/component.hpp \
    wiki-markup/components/components.hpp \
    wiki-markup/components/format.hpp \
    wiki-markup/components/header.hpp \
    wiki-markup/components/horizontal_line.hpp \
    wiki-markup/components/link.hpp \
    wiki-markup/components/list.hpp \
    wiki-markup/components/meta_info.hpp \
    wiki-markup/components/preformatted_text.hpp \
    wiki-markup/components/table.hpp \
    wiki-markup/components/text.hpp \
    wiki-markup/components/url.hpp \
    wiki-markup/parser/context_navigation.hpp \
    wiki-markup/parser/helpers.hpp \
    wiki-markup/parser/page_parser.hpp \
    wiki-markup/parser/parser_context.hpp \
    wiki-markup/parser/token.hpp \
    wiki-markup/parser/token_classification.hpp \
    wiki-markup/util/meta/apply.hpp \
    wiki-markup/util/meta/pop_front.hpp \
    wiki-markup/configuration.hpp \
    wiki-markup/main.hpp \
    wiki-markup/page.hpp \
    SimpleJSON/parse/jsd.h \
    SimpleJSON/parse/jsd_array.h \
    SimpleJSON/parse/jsd_atomic.h \
    SimpleJSON/parse/jsd_check.h \
    SimpleJSON/parse/jsd_container.h \
    SimpleJSON/parse/jsd_convenience.h \
    SimpleJSON/parse/jsd_core.h \
    SimpleJSON/parse/jsd_fundamental.h \
    SimpleJSON/parse/jsd_fusion_adapted_struct.h \
    SimpleJSON/parse/jsd_generic_parser.h \
    SimpleJSON/parse/jsd_map.h \
    SimpleJSON/parse/jsd_object.h \
    SimpleJSON/parse/jsd_optional.h \
    SimpleJSON/parse/jsd_options.h \
    SimpleJSON/parse/jsd_pair.h \
    SimpleJSON/parse/jsd_renamed.h \
    SimpleJSON/parse/jsd_set.h \
    SimpleJSON/parse/jsd_string.h \
    SimpleJSON/parse/jsd_unique_ptr.h \
    SimpleJSON/stringify/tmp_util/fundamental/eval_if.hpp \
    SimpleJSON/stringify/tmp_util/fundamental/identity.hpp \
    SimpleJSON/stringify/tmp_util/fundamental/integral.hpp \
    SimpleJSON/stringify/tmp_util/fundamental/is_same.hpp \
    SimpleJSON/stringify/tmp_util/fundamental/null_type.hpp \
    SimpleJSON/stringify/container_traits.h \
    SimpleJSON/stringify/integer_of_size.h \
    SimpleJSON/stringify/iterator_traits.h \
    SimpleJSON/stringify/jss.h \
    SimpleJSON/stringify/jss_array.h \
    SimpleJSON/stringify/jss_atomic.h \
    SimpleJSON/stringify/jss_bidirectional.h \
    SimpleJSON/stringify/jss_bitset.h \
    SimpleJSON/stringify/jss_check.h \
    SimpleJSON/stringify/jss_container.h \
    SimpleJSON/stringify/jss_convenience.h \
    SimpleJSON/stringify/jss_core.h \
    SimpleJSON/stringify/jss_deque.h \
    SimpleJSON/stringify/jss_error.h \
    SimpleJSON/stringify/jss_extended.h \
    SimpleJSON/stringify/jss_forward.h \
    SimpleJSON/stringify/jss_forward_list.h \
    SimpleJSON/stringify/jss_fundamental.h \
    SimpleJSON/stringify/jss_fusion_adapted_struct.h \
    SimpleJSON/stringify/jss_fusion_vector.h \
    SimpleJSON/stringify/jss_iterator.h \
    SimpleJSON/stringify/jss_list.h \
    SimpleJSON/stringify/jss_map.h \
    SimpleJSON/stringify/jss_mutex.h \
    SimpleJSON/stringify/jss_object.h \
    SimpleJSON/stringify/jss_optional.h \
    SimpleJSON/stringify/jss_options.h \
    SimpleJSON/stringify/jss_pair.h \
    SimpleJSON/stringify/jss_pointer.h \
    SimpleJSON/stringify/jss_queue.h \
    SimpleJSON/stringify/jss_random_access.h \
    SimpleJSON/stringify/jss_renamed.h \
    SimpleJSON/stringify/jss_set.h \
    SimpleJSON/stringify/jss_shared_ptr.h \
    SimpleJSON/stringify/jss_smart_ptr.h \
    SimpleJSON/stringify/jss_stack.h \
    SimpleJSON/stringify/jss_string.h \
    SimpleJSON/stringify/jss_tuple.h \
    SimpleJSON/stringify/jss_undefine.h \
    SimpleJSON/stringify/jss_unique_ptr.h \
    SimpleJSON/stringify/jss_valarray.h \
    SimpleJSON/stringify/jss_vector.h \
    SimpleJSON/stringify/jss_void.h \
    SimpleJSON/stringify/jss_weak_ptr.h \
    SimpleJSON/utility/base64.h \
    SimpleJSON/utility/beauty_stream.h \
    SimpleJSON/utility/meta_util.h \
    SimpleJSON/utility/rename.h \
    SimpleJSON/utility/xml_converter.h \
    SimpleJSON/test.h \
    SimpleUtil/value_ptr/cloneable.hpp \
    SimpleUtil/value_ptr/cloner.hpp \
    SimpleUtil/value_ptr/value_ptr.hpp

FORMS    += editor.ui
