#
# Demo seL4 Summit
#
# Copyright (C) 2022, HENSOLDT Cyber GmbH
#

cmake_minimum_required(VERSION 3.7.2)

project(demo_sel4_summit C)

DeclareCAmkESComponent(Client SOURCES components/Client/src/Client.c)
DeclareCAmkESComponent(Server SOURCES components/Server/src/Server.c)

DeclareCAmkESRootserver(demo_sel4_summit.camkes)