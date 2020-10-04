redCore architecture
====================

## Components

This section describes all the components that make up the redcore daemon.

### Listener

The **listener** dequeues packets in a non-blocking fashion from each ethernet interface in a round-robin fashion. All redPackets
are then added to that _queue_ of that **red interface** (`struct redInterface`).

### Processor

The **processor** has the job of processing packets from each **redInterface**'s queue and then passing them to the correct handler
for that packet's protocol type.