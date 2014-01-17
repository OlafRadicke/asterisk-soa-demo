
#include <stdexcept>

#ifndef CORE_TNTSOAEXCEPTION_H
#define CORE_TNTSOAEXCEPTION_H

/**
 * A exception class. This exception is help full to give more information
 * in the Browser. Tntnet catch this exception and return the error message
 * in the browser.
 */
namespace Core {

    class TntsoaException : public std::runtime_error
    {
        public:

            /**
             * @err_message This message is show in the browser.
             */
            explicit TntsoaException( const std::string& err_message )
                : std::runtime_error( err_message ){}
    };

} // end namespace 


#endif
