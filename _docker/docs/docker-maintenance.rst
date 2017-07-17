Docker Maintenance
##################

Use these basic commands to manage the docker files:

Check Docker Version
********************

..  code-block:: bash

    $ docker --version
    Docker version 17.06.0-ce, build 02c1d87

List All Running Containers
***************************

..  code-block:: bash

    $ docker ps -a

Stop all Containers
*******************

..  code-block:: bash

    $ docker kill $(docker ps -q)

List All Images
***************

..  code-block:: bash
    
    $ docker images -a

Remove all Images
*****************

This is a general reset command. All downloaded images will be removed.

..  code-block:: bash

    $ docker rmi $(docker images -a -q)

..  vim:ft=rst spell:
