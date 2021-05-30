## **Introduction**

The Mediator Design Pattern is a pattern that provides a central authority through which the different components of an application may communicate. 

When a Mediator is added to the system, all of the objects can be greatly simplified:
- They tell the Mediator when their state changes,
- They respond to requests from the Mediator.

Before adding an Admin as a Mediator, all of the participants needed to know all the rules about receiving messages of each other… it accidentally makes them all tightly coupled. With the Mediator in place, the participant objects are all *completely decoupled* from each other. 

<br/>

[<img src="../assets/img/01_Add_Mediator.png"/>](#)

<br/>

The Mediator contains all of the control logic for the entire system.

When an existing participant needs a new rule, or a new participant is added to the system, you will know that all of the necessary logic will be added to the mediator.

<br/>
<br/>

[<img align="left" width="2%" src="./../assets/icon/previous.png"/>](./P00_Problem.md "Problem")
[<img align="right" width="2%" src="./../assets/icon/next.png"/>](./P02_Structure.md "Structure")