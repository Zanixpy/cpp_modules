# Base Ubuntu LTS
FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Mise à jour + outils de base
RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
        build-essential \
        gdb \
        valgrind \
        clang \
        clangd \
        cmake \
        git \
        make \
        pkg-config \
        python3 \
        python3-pip \
        sudo \
        curl \
        ca-certificates \
        locales \
        nano \
        vim && \
    rm -rf /var/lib/apt/lists/*

# Locale en UTF-8
RUN locale-gen en_US.UTF-8 && \
    update-locale LANG=en_US.UTF-8

ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# Créer un utilisateur non-root "vscode" (conseillé pour VS Code)
RUN useradd -ms /bin/bash vscode && \
    usermod -aG sudo vscode && \
    echo "vscode ALL=(ALL) NOPASSWD: ALL" >> /etc/sudoers

USER vscode
WORKDIR /workspaces
