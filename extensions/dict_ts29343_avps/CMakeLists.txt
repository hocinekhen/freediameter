# The dict_ts29343_avps extension
PROJECT("dict_ts29343_avps library generated by FdGen " C)

# Compile as a module
FD_ADD_EXTENSION(dict_ts29343_avps dict_ts29343_avps.c)


####
## INSTALL section ##

INSTALL(TARGETS dict_ts29343_avps
	LIBRARY DESTINATION ${INSTALL_EXTENSIONS_SUFFIX}
COMPONENT freeDiameter-dictionary-TS29343_AVPS)



