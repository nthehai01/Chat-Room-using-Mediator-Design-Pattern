## Structure

<br/>

[<img src="../assets/img/02_General_Diagram.png"/>](#)

<br/>

- ```Mediator``` - defines the interface for communication between *Colleague* objects.

- ```ConcreteMediator``` -  implements the Mediator interface and coordinates communication between *Colleague* objects. It is aware of all of the *Colleagues* and their purposes with regards to inter-communication.

- ```Colleague``` - defines the interface for communication with other *Colleagues* through its *Mediator*.

- ```ConcreteColleague``` - implements the Colleague interface and communicates with other *Colleagues* through its *Mediator*.

<br/>
<br/>

[<img align="left" width="2%" src="./../assets/icon/previous.png"/>](./P01_Introduction.md "Introduction")
[<img align="right" width="2%" src="./../assets/icon/next.png"/>](./P03_Implementation.md "Implementation")