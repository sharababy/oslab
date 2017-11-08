# The Faneuil Hall problem

## The problem

There are three kinds of threads: immigrants, spectators, and a judge. Immigrants must wait in line, check in, and then sit down. At some point, the judge enters the building. When the judge is in the building, no one may enter, and the immigrants may not leave. Spectators may leave. Once all immigrants check in, the judge can confirm the naturalization. After the confirmation, the immigrants pick up their certificates of U.S. Citizenship. The judge leaves at some point after the confirmation. Spectators may now enter as before. After immigrants get their certificates, they may leave.

## The Constraints

. Immigrants must invoke enter, checkIn, sitDown, swear, getCertificate and leave.
. The judge invokes enter, confirm and leave.
. Spectators invoke enter, spectate and leave.
. While the judge is in the building, no one may enter and immigrants may not leave.
. The judge can not confirm until all immigrants who have invoked enter have also invoked checkIn.
. Immigrants can not getCertificate until the judge has executed confirm.

## How to Run

Open the ```index.html``` file in any browser (preferably Google Chrome) to run the simulation.