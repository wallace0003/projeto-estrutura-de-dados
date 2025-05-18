# 🏥 Projeto - Gerenciador de Atendimento Médico

## 📘 Descrição

Este projeto foi desenvolvido como parte da disciplina de **Estrutura de Dados** do curso de **Ciência da Computação** - 1º semestre de 2025, no **Centro Universitário FEI**, sob orientação do Prof. Luciano Rossi.

O sistema simula o gerenciamento de atendimentos em um serviço de saúde, utilizando diversas estruturas de dados clássicas: lista encadeada, fila, heap (fila de prioridade), árvore binária de busca e pilha.

---

## 🧠 Funcionalidades

### 📋 1. Cadastrar Paciente
- Inserção de novos pacientes em uma **lista encadeada**.
- Consultar paciente por RG.
- Atualizar dados do paciente.
- Remover paciente por RG.
- Listar todos os pacientes cadastrados.

### 🧾 2. Atendimento (Fila Comum)
- Paciente é enfileirado em uma **fila FIFO**.
- Realizar atendimento (desenfileirar).
- Mostrar fila de atendimento.

### 🔺 3. Atendimento Prioritário
- Pacientes são enfileirados em um **heap de máximo** baseado na idade.
- Atender paciente com maior prioridade (idade).
- Mostrar a fila prioritária.

### 🔍 4. Pesquisa (Árvore Binária de Busca)
- Montagem de árvore binária com os pacientes cadastrados.
- Mostrar registros ordenados por:
  - Ano de entrada
  - Mês de entrada
  - Dia de entrada
  - Idade

### ⬅️ 5. Desfazer Operações
- Utiliza uma **pilha** para armazenar operações feitas na fila de atendimento.
- Mostrar o histórico (log).
- Desfazer a última operação com confirmação do usuário.

### 💾 6. Salvar / Carregar
- Salvar os dados da fila (normal e prioritária) em arquivo `.txt`.
- Carregar dados do arquivo mantendo a ordem de inserção.

### 👨‍💻 7. Sobre
- Mostra informações dos desenvolvedores:
  - Nome
  - RA
  - Curso
  - Disciplina
  - Data
  - Ciclo
---

## 🛠️ Estruturas Utilizadas

| Estrutura | Utilização |
|----------|------------|
| Lista Encadeada | Cadastro de pacientes |
| Fila | Atendimento comum |
| Heap Máximo | Atendimento prioritário por idade |
| Árvore Binária | Pesquisa e ordenação |
| Pilha | Histórico de operações e desfazer |
---
