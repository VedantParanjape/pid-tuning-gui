# Edit following two lines to set component requirements (see docs)
set(COMPONENT_REQUIRES )
set(COMPONENT_PRIV_REQUIRES )

set(COMPONENT_SRCS "main.c json_handler.c udp_handler.cpp")
set(COMPONENT_ADD_INCLUDEDIRS "include")

register_component()
