# 1300-ElecFinalProj


This program allows the user to find out demographic details about a certain population based on gender and userID criteria, as well as performing calculations of electricity consumption based on the demographic and electricity data collected from that population for 31 days.
It is dependent on the electricity and demographic data files given to us.

When the program is first run, it prints out a menu that the user can choose from.  There are 6 different options for different operations the program can perform while interacting with the demographic and electricity usage date provided in the .csv files


FURTHER DETAILS: (program explained)
Menu options 1-4 use class ElecUser - option 1 has to do with electricity data file, and options 2-4 only use the demogrpahic data file. Options 5 and 6 use class User2, and use both data files.   

Option 1 calculates total, max and average values of electricity consumption for one user.  Uses class ElecUser to read through electricity data file - note that ElecUser class keeps electricity and demographic data files separate.  (demonstrates use of arrays to store data)

Options 2 and 3 operate similarly.  They use the class ElecUser to read demographic data - and checks work status (works from home or not), and whethr their job was a STEM job or not).  (demonstrates use of boolean values)

Option 4 returns what type of house the user had, by reading through demographic data.  (demonstrates converting types, ie: string to private integer)

Option 5 calculates total electricity consumption for all users w/ even or odd# user IDs, and uses class User2 (demonstrates usage of arrays and indexing)

Option 6 calculates average electricity usage for male or female users, and uses both electricity and demographic data files.  (userIDs placed into array, gender assigned to boolean value and uses the same index.  userID was related to gender at that index, and user's ID could be read from electricity data file)
