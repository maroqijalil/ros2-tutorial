cmake_minimum_required(VERSION 3.5)
project(subnode_test)

if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -fPIC)
endif()

find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(std_srvs REQUIRED)
find_package(more_interfaces REQUIRED)

add_library(${PROJECT_NAME} SHARED
  "src/${PROJECT_NAME}/bar/bar_node.cpp"
  "src/${PROJECT_NAME}/foo/foo_node.cpp"
  "src/${PROJECT_NAME}/node.cpp")

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)

ament_target_dependencies(${PROJECT_NAME}
  rclcpp
  more_interfaces
  std_msgs
  std_srvs)

install(DIRECTORY "include" DESTINATION ".")

install(TARGETS ${PROJECT_NAME}
  EXPORT export_${PROJECT_NAME}
  ARCHIVE DESTINATION "lib"
  LIBRARY DESTINATION "lib"
  RUNTIME DESTINATION "bin")

add_executable(main_test "src/main_test.cpp")
target_include_directories(main_test PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(main_test ${PROJECT_NAME})

add_executable(subscriber_test "src/subscriber_test.cpp")
target_include_directories(subscriber_test PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(subscriber_test ${PROJECT_NAME})

add_executable(client "src/client.cpp")
target_include_directories(client PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(client ${PROJECT_NAME})

add_executable(subscriber "src/subscriber.cpp")
target_include_directories(subscriber PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
target_link_libraries(subscriber ${PROJECT_NAME})

install(TARGETS
  main_test
  subscriber_test
  client
  subscriber
  DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_export_dependencies(
  rclcpp
  std_msgs
  std_srvs)
ament_export_include_directories("include")
ament_export_libraries(${PROJECT_NAME})
ament_package()
