#include "style_sheet_preprocessor.hpp"

#include <QtGlobal>
#include <QDebug>

#include <boost/wave.hpp>
#include <boost/wave/cpplexer/cpp_lex_token.hpp>    // token class
#include <boost/wave/cpplexer/cpp_lex_iterator.hpp> // lexer class

#include <string>
#include <sstream>
#include <iomanip>

std::string preprocessStyleSheet(std::string styleSheet)
{
    typedef boost::wave::cpplexer::lex_iterator<
            boost::wave::cpplexer::lex_token<> >
        lex_iterator_type;
    typedef boost::wave::context<
            std::string::iterator, lex_iterator_type>
        context_type;

    context_type ctx(styleSheet.begin(), styleSheet.end(), "stylesheet.qss");

    std::stringstream version;
    version << "0x" << std::hex << std::setw(6) << QT_VERSION;

    ctx.add_macro_definition(std::string("QT_VERSION=") + version.str(), true);
    ctx.add_macro_definition("STYLE_PROCESSOR_VERSION=0x0000", true);

    context_type::iterator_type first = ctx.begin();
    context_type::iterator_type last = ctx.end();

    std::stringstream result;
    try
    {
        for (; first != last; ++first)
        {
            auto id = (boost::wave::token_id)(*first);
            // skip line marks
            if (id == boost::wave::T_PP_LINE)
            {
                for (; first != last && ![&first](){return (boost::wave::token_id)(*first) == boost::wave::T_NEWLINE;}(); ++first);
                continue;
            }

            result << first->get_value();
        }
    }
    catch (boost::wave::preprocess_exception const& exc)
    {
        qDebug() << "style could not be preprocessed: " << exc.what();
    }
    return result.str();
}
