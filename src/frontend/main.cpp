/**
* @author Olaf Radicke <briefkasten@olaf-rdicke.de>
* @date 2013
* @copyright GNU Affero General Public License
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU Affero General Public License as published by
* the Free Software Foundation, either version 3 of the License, or later
* version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Affero General Public License for more details.
*
* You should have received a copy of the GNU Affero General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Core/models/Config.h>

#include <tnt/tntnet.h>
#include <tnt/configurator.h>
#include <string>
#include <cxxtools/log.h>

log_define("TNTSOABACKEND")

int main ( int argc, char* argv[] )
{
    try
    {
        /* Read the config */
        Core:Config& config = Config::it();
        config.read();
        /* init the logging */
        log_init( config.logging() );

        // Init Application Server
        tnt::Tntnet app;
        tnt::Configurator tntConfigurator( app );
        tntConfigurator.setSessionTimeout( config.sessionTimeout() );
        app.listen(
            config.appIp(),
            config.appPort()
        );

        // configure static stuff
        app.mapUrl("^/Core/resources/(.*)", "resources")
           .setPathInfo("Core/resources/$1");
        app.mapUrl("^/Core/favicon.ico$", "resources")
           .setPathInfo("Core/resources/favicon.ico");

        // default route for /
        app.mapUrl( "^/$", "StatusView" );

        std::cout << "############################################" << std::endl;
        std::cout << "tntsoafrontend is started and run on http://" << config.appIp()
            << ":" <<  config.appPort() << "/" << std::endl;
        std::cout << "############################################" << std::endl;

        log_info(
            "tntsoafrontend is started and run on http://" <<  config.appIp() \
            << ":" <<  config.appPort() << "/"
        );

        app.run();
    } catch ( const std::exception& e )
    {
        std::cerr << e.what() << std::endl;
    }
}
