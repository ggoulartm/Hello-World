# Install script for directory: /home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/build/_install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mqtt" TYPE FILE FILES
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/async_client.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/buffer_ref.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/buffer_view.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/callback.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/client.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/connect_options.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/create_options.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/delivery_token.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/disconnect_options.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/exception.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/iaction_listener.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/iasync_client.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/iclient_persistence.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/message.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/properties.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/response_options.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/server_response.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/ssl_options.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/string_collection.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/subscribe_options.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/thread_queue.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/token.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/topic.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/types.h"
    "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/will_options.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ggmuller/ggmller/embeddedSYSTEMS/Telemetria_VS/linux/mqtt/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
