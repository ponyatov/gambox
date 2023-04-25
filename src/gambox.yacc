%{
	#include "gambox.hpp"
%}

%defines %union { Object* o; }

%type<o>    ex
%token<o>   COLON SEMICOLON
%token<o>   SYM NUM

%%
grammar : | grammar ex

ex : COLON SYM { $$ = new Seq($2->val()); }
   | SEMICOLON
   | SYM
   | NUM
