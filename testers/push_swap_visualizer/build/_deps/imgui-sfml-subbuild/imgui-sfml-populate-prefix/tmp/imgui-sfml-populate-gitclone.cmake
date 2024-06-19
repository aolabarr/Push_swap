
if(NOT "/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/imgui-sfml-populate-gitinfo.txt" IS_NEWER_THAN "/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/imgui-sfml-populate-gitclone-lastrun.txt")
  message(STATUS "Avoiding repeated git clone, stamp file is up to date: '/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/imgui-sfml-populate-gitclone-lastrun.txt'")
  return()
endif()

execute_process(
  COMMAND ${CMAKE_COMMAND} -E rm -rf "/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to remove directory: '/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-src'")
endif()

# try the clone 3 times in case there is an odd git clone issue
set(error_code 1)
set(number_of_tries 0)
while(error_code AND number_of_tries LESS 3)
  execute_process(
    COMMAND "/usr/bin/git"  clone --no-checkout --config "advice.detachedHead=false" "https://github.com/eliasdaler/imgui-sfml" "imgui-sfml-src"
    WORKING_DIRECTORY "/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps"
    RESULT_VARIABLE error_code
    )
  math(EXPR number_of_tries "${number_of_tries} + 1")
endwhile()
if(number_of_tries GREATER 1)
  message(STATUS "Had to git clone more than once:
          ${number_of_tries} times.")
endif()
if(error_code)
  message(FATAL_ERROR "Failed to clone repository: 'https://github.com/eliasdaler/imgui-sfml'")
endif()

execute_process(
  COMMAND "/usr/bin/git"  checkout 82dc2033e51b8323857c3ae1cf1f458b3a933c35 --
  WORKING_DIRECTORY "/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-src"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to checkout tag: '82dc2033e51b8323857c3ae1cf1f458b3a933c35'")
endif()

set(init_submodules TRUE)
if(init_submodules)
  execute_process(
    COMMAND "/usr/bin/git"  submodule update --recursive --init 
    WORKING_DIRECTORY "/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-src"
    RESULT_VARIABLE error_code
    )
endif()
if(error_code)
  message(FATAL_ERROR "Failed to update submodules in: '/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-src'")
endif()

# Complete success, update the script-last-run stamp file:
#
execute_process(
  COMMAND ${CMAKE_COMMAND} -E copy
    "/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/imgui-sfml-populate-gitinfo.txt"
    "/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/imgui-sfml-populate-gitclone-lastrun.txt"
  RESULT_VARIABLE error_code
  )
if(error_code)
  message(FATAL_ERROR "Failed to copy script-last-run stamp file: '/home/aolabarr/01_cursus/02_repo/push_swap_v1/push_swap_visualizer/build/_deps/imgui-sfml-subbuild/imgui-sfml-populate-prefix/src/imgui-sfml-populate-stamp/imgui-sfml-populate-gitclone-lastrun.txt'")
endif()

