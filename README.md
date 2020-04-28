	
# Uppvaknandet
## Sammanfattning

*Uppvaknandet* är en svensk tolkning av The Awakening, ett interaktivt 
parseräventyr, skrivet av Dennis Matheson år 1998.

# Grundfakta

- Översättning och tolkning: Björn Paulsen
- Motor: z-machine, svenska Inform (Lib611)
- Speltest:	Fredrik Ramsberg och Johan Berntsson
- Verktyg och hjälpmedel: Fredrik Ramsberg

# Ändringar

## Tekniska detaljer
Jämför man Awakening med Uppvaknandet har den senare filen växt med drygt 40. Omfattande förändringar har gjorts för att få Awakening att fungera i svensk kontext.

* Swedish Inform använder en nyare version av standardbiblioteket. Detta är större till sitt omfång. 
* The Awakening är från 1998. Det gör att vissa bekvämlighetsmässiga förväntningar saknas, och fick därför läggas till översättningen. Således matchar tolken betydligt fler av de saker som texten omnämner. Detta inkluderar svenska synonymer och adjektivformer, och i vissa fall att lägga till föremål som aldrig existerade trots att de borde funnits i spelet. Spelet förstår nu också vad man menar när man vill gå IN eller UT ur byggnader.
* Ett flertal buggar har fixas. I synnerhet implementation av rep och stege fungerade inte helt korrekt, och har därför rättats till.

# Diverse info

GitHubs system för diffning verkar inte kunna återge svenska tecken. Detta btyder inte att filen är korrupt, bara att själva diff-motorn är dålig och därför ersätter åäö med U+FFFD (bokstaven �).

De extensions jag har modifierat för att fungera med Inform på Svenska är precis som detta bibliotek märkta med prefixet Swe. De vars namn saknar det prefixet ska vara snarlika nuvarande officiella version på Informs hemsida.
