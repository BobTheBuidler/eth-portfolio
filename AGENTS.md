# Agent Requirements

All agents must follow these rules:

1) Fully test your changes before submitting a PR (run the full suite or all relevant tests).
2) PR titles must be descriptive and follow Conventional Commits-style prefixes:
   - Common: `feat:`, `fix:`, `chore:`, `refactor:`, `docs:`, `test:`, `perf:`
   - Support titles: `fix(docs):`, `fix(benchmarks):`, `fix(cicd):`
3) If you touch ypricemagic-driven price lookups or related docs, keep the `y.stuck?` logger guidance accurate (DEBUG-only, 5-minute interval) so long-running calls can be diagnosed.

Reference: https://www.conventionalcommits.org/en/v1.0.0/
