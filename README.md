# Overview
The Nexus Unreal Engine Software Development Kit (Nexus UE SDK) serves as the bridge between Unreal Engine and Nexus services. It offers a high-level user-friendly way to integrate both Nexus **Support-A-Creator**, and **Referral & Bounties** programs into an Unreal Engine project.

## Supported Unreal Engine Versions
Unreal Engine 5.1

Unreal Engine 5.0

Unreal Engine 4.27

Unreal Engine 4.26

## Setup
### Install
Download or clone the repository and place the contents under the project's **Plugins** folder 

### Configuration

Add public dependency module to the project's Build.cs
```
PublicDependencyModuleNames.AddRange(new string[] 
{ 
     "NexusUnrealSDK",
});
```

Then enable the plugin by launching the engine, then navigate to Edit -> Plugins -> Check "NexusUnrealSDK"

## Features
### Nexus API
Included in the SDK are a number of functions used to communicate with Nexus services.
Documentation for each API can be found here: 
- [Attribution (Creator Program) API](https://app.swaggerhub.com/apis-docs/nexus-gg/Attribution/1.5.1)
- [Referral API](https://app.swaggerhub.com/apis-docs/nexus-gg/Referral/1.0.0)
- [Bounty API](https://app.swaggerhub.com/apis-docs/nexus-gg/Bounty/1.0.0)

### Blueprint support 

// TODO
<!TODO–>

## Nexus Unreal Engine Sample Project
The Nexus Unreal Engine Sample Project serves as an aid in integrating the Nexus UE SDK with an Unreal Engine project. Included are example UI which showcase the Nexus Support-A-Creator, and Referral & Bounties programs. The repository can be found [here.](https://github.com/bluequest/nexus-unreal-example)
