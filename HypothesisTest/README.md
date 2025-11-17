# Hypothesis Testing in Particle Physics

This repository contains the material for the hands-on session on **hypothesis testing in particle physics**.  
We will work with an interactive **Jupyter Notebook**, so please make sure you have all the required libraries installed before the session.

---

## Required Python Libraries

These packages are needed to run the notebook:

| Library | Purpose |
|---------|---------|
| **uproot** | To read ROOT files (commonly used in high-energy physics). |
| **numpy** | Numerical computing and array manipulation. |
| **scipy** | Mathematical functions, optimization, and statistics. |
| **matplotlib** | Plotting tools (2D and 3D visualization). |
| **jupyterlab-myst** | Extended Markdown support inside Jupyter notebooks. |

---

## Installation Instructions

You can install dependencies using **conda** or **pip**.

---

### Option A — Using conda (recommended)

If you have **Anaconda** or **Miniconda**, run (in a new or existing envorinment):

```bash
conda install -c conda-forge uproot numpy scipy matplotlib 
pip install jupyterlab-myst
```

### Option B — Using pip

If you prefer pip (for example inside a venv virtual environment):
```bash
pip install uproot numpy scipy matplotlib jupyterlab-myst
```
