cmake_minimum_required(VERSION 2.8.12)
set(CMAKE_BUILD_TYPE Debug)
include_directories(${PROJECT_SOURCE_DIR}/include)
set(SERVER_SRCS "chat_server.c"
                "common.c"
                "server_api.c")
set(CLIENT_SRCS "chat_client.c"
                "common.c"
                "client_api.c")
find_package (Threads)
add_executable(chat_server ${SERVER_SRCS})
add_executable(chat_client ${CLIENT_SRCS})
target_link_libraries(chat_server ${CMAKE_THREAD_LIBS_INIT})
