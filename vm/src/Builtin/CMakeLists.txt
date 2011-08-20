add_library(Builtin STATIC String.cpp String.h 
				Method.cpp Method.h 
				class.cpp  class.h 
				#OFXClass.cpp OFXClass.h
				#list.cpp list.h
				Shell.cpp  Shell.h                               
				object.cpp object.h
				Stackable.cpp Stackable.h
				tuple.cpp tuple.h
				Integer.cpp Integer.h
				Boolean.cpp Boolean.h
)