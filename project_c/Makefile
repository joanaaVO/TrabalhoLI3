FLAGS= -std=c99 -Wextra -O2 -D_GNU_SOURCE
PKG = `pkg-config --cflags --libs glib-2.0` -lm
COMPILER=gcc
MODELOS_INCLUDES=Modelos/Includes
MODELOS_SOURCES=Modelos/sources
CONTROLER_INCLUDES = Controladores/Includes
CONTROLER_SOURCES = Controladores/Sources
VIEW_SOURCES = View
VIEW_INCLUDES = View

OBJ=obj


program: data user users review reviews business businesses structs_aux sgr table yelp interpretador view

data: $(MODELOS_SOURCES)/data.c $(MODELOS_INCLUDES)/data.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/data.o $(PKG) -c $(MODELOS_SOURCES)/data.c

user: $(MODELOS_SOURCES)/user.c $(MODELOS_INCLUDES)/user.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/user.o $(PKG) -c $(MODELOS_SOURCES)/user.c

users: $(MODELOS_SOURCES)/users.c $(MODELOS_INCLUDES)/users.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/users.o $(PKG) -c $(MODELOS_SOURCES)/users.c

review: $(MODELOS_SOURCES)/review.c $(MODELOS_INCLUDES)/review.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/review.o $(PKG) -c $(MODELOS_SOURCES)/review.c

reviews: $(MODELOS_SOURCES)/reviews.c $(MODELOS_INCLUDES)/reviews.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/reviews.o $(PKG) -c $(MODELOS_SOURCES)/reviews.c

business: $(MODELOS_SOURCES)/business.c $(MODELOS_INCLUDES)/business.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/business.o $(PKG) -c $(MODELOS_SOURCES)/business.c

businesses: $(MODELOS_SOURCES)/businesses.c $(MODELOS_INCLUDES)/businesses.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/businesses.o $(PKG) -c $(MODELOS_SOURCES)/businesses.c

sgr: $(MODELOS_SOURCES)/sgr.c $(MODELOS_INCLUDES)/sgr.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/sgr.o $(PKG) -c $(MODELOS_SOURCES)/sgr.c

structs_aux: $(MODELOS_SOURCES)/structs_aux.c $(MODELOS_INCLUDES)/structs_aux.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/structs_aux.o $(PKG) -c $(MODELOS_SOURCES)/structs_aux.c

table: $(MODELOS_SOURCES)/table.c $(MODELOS_INCLUDES)/table.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/table.o $(PKG) -c $(MODELOS_SOURCES)/table.c

yelp: $(CONTROLER_SOURCES)/yelp.c $(CONTROLER_INCLUDES)/yelp.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/yelp.o $(PKG) -c $(CONTROLER_SOURCES)/yelp.c

interpretador: $(CONTROLER_SOURCES)/interpretador.c $(CONTROLER_INCLUDES)/interpretador.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/interpretador.o $(PKG) -c $(CONTROLER_SOURCES)/interpretador.c

view: $(VIEW_SOURCES)/view.c $(VIEW_INCLUDES)/view.h
	$(COMPILER) $(FLAGS) -o $(OBJ)/view.o $(PKG) -c $(VIEW_SOURCES)/view.c
	


allprog: $(CONTROLER_SOURCES)/yelp.c $(OBJ)/yelp.o $(OBJ)/interpretador.o $(OBJ)/sgr.o $(OBJ)/structs_aux.o $(OBJ)/table.o $(OBJ)/data.o $(OBJ)/user.o $(OBJ)/users.o $(OBJ)/review.o $(OBJ)/reviews.o $(OBJ)/business.o $(OBJ)/businesses.o $(OBJ)/view.o
	$(COMPILER) $(FLAGS) $(OBJ)/data.o $(OBJ)/user.o $(OBJ)/users.o $(OBJ)/review.o $(OBJ)/reviews.o $(OBJ)/business.o $(OBJ)/businesses.o $(OBJ)/sgr.o $(OBJ)/structs_aux.o $(OBJ)/table.o $(OBJ)/view.o $(OBJ)/yelp.o $(OBJ)/interpretador.o $(PKG) -o program 

memcheck:
	valgrind --leak-check=yes ./program

clean:
	rm -rf $(OBJ)/*.o program
