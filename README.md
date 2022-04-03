	
# Uppvaknandet
## Sammanfattning

*Uppvaknandet* är en svensk tolkning av The Awakening, ett interaktivt 
parseräventyr, skrivet av Dennis Matheson år 1998.

## Grundfakta

- Senaste version: v1.8 beta
- Översättning och tolkning: Björn Paulsen
- Motor: z-machine/Glulx, svenska Inform (Lib611, Inform 6.36 Library 6/11 S)
- Speltest:	Fredrik Ramsberg, Johan Berntsson, "itsgallus"
- Verktyg och hjälpmedel: Fredrik Ramsberg

## Ändringar

### Tekniska detaljer
Jämför man Awakening med Uppvaknandet har den senare filen växt med drygt 40 kB. Omfattande förändringar har gjorts för att få Awakening att fungera i svensk kontext.

* Swedish Inform använder en nyare version av standardbiblioteket. Det har helt enkelt större omfång, och väger därefter. 
* The Awakening kom ut år 1998. Det gör att vissa bekvämlighetsmässiga förväntningar från nutida IF helt enkelt saknas, och således fick läggas till i samband med översättningen. Därmed matchar tolken betydligt fler av de företeelser som omnämns i texten. Den accepterar också vanligt förekommande svenska synonymer och adjektivformer. En uppsjö omnämnda föremål som saknades har implementerats. Uppvaknandet förstår nu också vad man menar när man vill gå IN eller UT ur byggnader.
* En handfull regelrätta buggar har fixas. I synnerhet implementation av rep och stege kunde bugga ur rejält, och har därför rättats till.
* Smärre ändringar har utförts för att hantera underligheter eller självmotsägelser i berättelsen.  

## Diverse info

GitHubs system för diffning verkar inte kunna återge svenska tecken. Detta betyder inte att filen är korrupt, bara att själva diff-motorn är usel och därför ersätter åäö med U+FFFD (bokstaven �).

De extensions jag har modifierat för att fungera med Inform på Svenska är precis som detta bibliotek märkta med prefixet Swe. De vars namn saknar det prefixet ska vara snarlika nuvarande officiella version på Informs hemsida. 

Hjälpmeny-systemet fungerar för närvarande under Glulx, men detta garanteras hittills bara inom den "hot path" som spelets rutiner använder sig av. Att t.ex. bygga ett nytt spel under z3, eller att använda menyfunktionalitet på ett annorlunda sätt än det Uppvaknandet gör, kommer förmodligen att blotta fler brister. Kosmetiska buggar har redan noterats och kommer att åtgärdas framöver.
