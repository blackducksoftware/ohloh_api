## Kudo Score

Every night, a KudoScore is generated for every Open Hub Account and Project contributor (collectively called ‘participants’ here). These scores are derived from the [Kudos](kudo.md) sent between participants. You can read a general outline of the KudoRank algorithm [here](http://blog.openhub.net/kudos/).

Not everyone has a KudoScore. Because KudoScores are calculated only once per day, new Accounts and contributors may not have a kudo score. On the Open Hub web site, unscored Accounts and contributors are displayed with a default KudoRank of 1.

### Properties

+ __kudo_rank__
    The KudoRank, which is an integer from 1 to 10. Higher ranks are better. KudoRanks are assigned on a curve, with a certain fraction of people receiving each KudoRank.
+ __position__
    An integer which orders all participants. The person with `position` equals 1 is the highest-ranked person on Open Hub.

### URL
KudoScores cannot be queried directly. They are always returned within an [Account](account.md) record.
