!       SweHints        Ett Inform 6 - bibliotek av L. Ross Raszewski,
!             till svenskan av Björn Paulsen
!     baserad på Version 2
!   Syfte:      Att erbjuda ledtrådar på ett smidigt sätt.
!                       Grundläggande översatt och
!
! KRÄVER SweDoMenu.H och AltMenu.H (kan laddas ner från hemsidan)
!
! OBS: Objekten som används i denna extension dyker upp när ÖRNKOLL används.
!      Användningsområdet för det beteendet är tveksamt, och därför
!      kan det lämpligen ersättas i din källkod på följande vis, genom
!      att man ersätter raden
!
!     #Include "SweAlpha";
!
!      med följande rad:
!
!
! Replace _CheckThisObj;
! Include "SweAlpha";
!
! ! Fixar så att Örnkoll inte bryr sig om meny-objekt.
! [_CheckThisObj obj   j isNormalObj;
!   isNormalObj=(parent(obj)~=0 || obj hasnt light) && ~~( obj ofclass HintTopic || obj ofclass SwitchOption || obj ofclass Option || obj ofclass Hint || obj ofclass Menu);
!   if(isNormalObj && parent(obj)==0) { ! Check if dark, lonely objects have exits
!   objectloop(j in compass) isNormalObj=isNormalObj && (obj.(j.door_dir)==0);
!   }
!   return isNormalObj;
! ];
!
! Detta gör helt enkelt att ÖRNKOLL ignorerar menyobjekten. I övrigt
!   är extensionen självständig och kräver ingen editering av befintliga
!   biblioteksfiler.
!
! Historik v2.1:
!
! Översatte fasta textmeddelande, understand tokens, etc.
! Lite dokumentationstext. Lade till svenska kommandon.
!
! Historik v2.0:
!
!   New in this version: The hint may now be in the short_name rather than the
!      descriptionof the hint.  I don't know what I was thinking.
!   Multilingual support.
!   The hints left descriptor has been moved to the function HintIdent, which
!        you may replace if you so desire.  Hintident is called with three
!               arguments, x - set to 1 before the hint is printed, 2 after.
!                          i - the number of hints left
!                          j - the total number of hints
!
!   The hint_menu no longer needs to be called hint_menu.  in fact, it can't,
!       unless it's defined before inclusion. Instead, set the global hint_menu
!       equal to your hint menu.
!  Predefine Helpsub to change its message.
! define NO_GRAMMAR to prevent the grammar from being included.
!
! Upon reflection, the older version of this library was clumsy and inflexible
! This system is well suited to adaptive hints and other wonderful things.
! Grammar -
! The verb "Hint" ("Help") calls up the hint menu, which should begin with an
! AltMenu Menu object called hint_menu.  (The first time, you are given the
! option to disable the hints.)
! The children of hint_menu should be the top level hints or categories, and
! so on etc until you reach the actual hints.  The hint categories are
! objects of the class "HintTopic", whose short names are the names of the
! hints.  The children of a HintTopic are of class Hint.  Their descriptions
! contain the actual hints, which are displayed in order.
! Example hierarchy (This is NOT code, it's more a sort of tree):
!       Menu hint_menu
!           Menu "Prologue"
!               HintTopic "What do I do here?"
!                       Hint with desc. "Look around."
!                       Hint w/d "Move around."
!           Menu "Part 1"
!               HintTopic "Who am I?"
!                       Hint w/d "You are Perry Simm"
!               HintTopic "What Do I do?"
!                       Hint w/d "Not a lot"
!                       Hint w/d "Nothing at all"
!                       Hint w/d "because this ain't a real game"
!
! The player sees the menu titled whatever you choose to call the hint_menu,
! on which an option is Prologue.  Under prologue is the option
! "What do I do here?"  Selecting that will display "Look Around".  If the
! player asks for another hint, he gets it.  if not, revealed hints are
! re-reveled when he reenters the menu.  That is, if the player had read
! the first two hints under "What do I do", then went back to the game, he
! could at any time go back to the hint menu, navigate to "What do I do"
! and would automatically have the first two hints displayed.
! HINT_STYLE must be defined before inclusion (or else it defaults to 0)
!  if it's 0, then the hint is displayed thus:
!       Not a lot (2 left)
!  if it's 1, you get:
!       Not a lot [1/4]
!  if it's 2, you get:
!     [3 hints left]-> Not a lot
!     [2 hints left]->
! (Note that when it's 2, you don't get the first hint when you first
! enter a topic; you get [x hints left]-> )
!
! You can move the hintTopics about, or even do wretched things to
! their children. (I wouldn't, but you can)  In an adaptive hint system,
! you could nove the appropriate HintTopic (with its children already inside)
! into the hint_menu when you want the hint available.
!
! The title_bar property of a HintTopic specifies the top line of the hint
! status line.  It defaults to "InvisiHints"  I've included WaitForKey();
! in case you don't have it already.
!
! Questions, comments, rude suggestions?  I'm at rraszews@skipjack.bluecrab.org
System_file;
#ifndef hint_menu;
global hint_menu;
#endif;
#IFNDEF LASTH__TX;
Constant LASTH__TX = "^^^[Det var allt, gott folk!]^";
#ENDIF;
#IFNDEF HINTD__TX;
Constant HINTD__TX = "LEDTRÅDAR avstängda.";
#ENDIF;
#IFNDEF WaitForKey;
[ WaitForKey str;
if (str==0) str="(Tryck för att fortsätta)";
print (string) str;
KeyCharPrimitive();
];
#EndIf;

[ HintIdent x i j;
                switch(x){
                        1: if (HINT_STYLE==2) {
                                print "[",i, " ledtråd";
                                if (i>1) print "ar";
                                print " kvar]-> ";
                                return 1;}
                        2: if (HINT_STYLE==1) {
                                j=children(self)-i;
                                print " [",j,"/",j+i,"]";
                                };
                           if (HINT_STYLE==0) {
                                print " (", i, " ledtråd";
                                if (i>1) print "ar";
                                print " kvar.)";
                                }
                                }
return 0;
];

#IFNDEF Hintsub;
[ HintSub;
        if (hint_menu hasnt general)
        {print "[Varning: Det bör nämnas att frestelsen att när som helst \
        begära en ledtråd kan växa sig så stark att du kanske begär hjälp i \
        förtid. Därför kan du när som helst under berättelsens gång skriva \
        LEDTRÅDAR AV, vilket stänger av möjligheten att begära hjälp under \
        förestående spelsession. Om du fortfarande vill ha en ledtråd nu, \
        svara med LEDTRÅD.]"; give hint_menu general;
         rtrue;}
        if (hint_menu has locked)
                print_ret "Ledtrådar är avstängda.";
hint_menu.select();
];
#ENDIF;
[ HintOffSub;
        print (string) HINTD__TX;
        give hint_menu locked;
        rtrue;
        ];
#ifndef HINT_STYLE;
Constant HINT_STYLE 0;
#ENDIF;
Class HintTopic
        class Option,
        with    printsn [; print (name) self;],
                number 0,
                title_bar "InvisiHints",
                select [ o i j;
                         if (pretty_flag==0) {
                                self.title_bar();
                                self.printsn();
                                print "^Tryck ENTER för en till ledtråd, X för
                                        att återgå till menyn.";
                                jump disph;
                                }
                         ClearScreen(WIN_ALL);
                         StatusLineHeight(3);
                         i=0->33; if (i==0) i=80;
                         MoveCursor(1, 1);
                         style reverse;
                         spaces(i);
                         CenterU(self.title_bar,1);
                         MoveCursor(2, 1); spaces (i);
                         style bold;
                         CenterU(self.printsn,2);
                style roman; style reverse;
                MoveCursor(3, 1); spaces(i);
                MoveCursor(3, 2); print "RETURN = läs ledtråd";
                j=i-17; MoveCursor(3, j);
                print "X = föregående meny";
                style roman; font off;
                MainWindow(0);
                .disph;
                print "^^^^^";
                i=0;
                objectloop (o in self) {
                        if (o has general) { o.GiveHint(); new_line; i++;}
                        }
                i=children(self)-i;
                if (i==0) { WaitForKey(LASTH__TX); return 2;}
                for (o=child(self):o has general:o=sibling(o));
                do {
                if (HintIdent(1,i,j)==1) {

                do { i = KeyCharPrimitive(); } until (j == 'Q' or 'q' or 'x' or 'X' or 27
                                                 or 10 or 13 or 132);
                if (j== 'Q' or 'q' or 'x' or 'X' or 27) return 2;
                if (j== 10 or 13 or 132) o.GiveHint();
                i--;
                jump loopover;
                }
                o.GiveHint();
                i--;
                if (i==0) jump loopover;
                HintIdent(2,i,j);
                do { j = KeyCharPrimitive(); } until (j == 'Q' or 'q' or 'x' or 'X' or 27
                                                 or 10 or 13 or 132);
                if (j== 'Q' or 'q' or 'x' or 'X' or 27) { give o ~general; return 2;}
                .loopover;
                o=sibling(o);
                new_line;
                } until (i==0);
                WaitForKey(LASTH__TX); return 2;
                ];
Class Hint
        with GiveHint [;
                        if (self provides description)
                                PrintOrRun(self,description,1);
                          else print (name) self;
                         give self general;];


#IFNDEF NO_GRAMMAR;
Verb meta "ledtråd" "ledtrådar" "hint"  "hints"
                                * "av"                         ->HintOff
                                *                               ->Hint;
#ENDIF;
