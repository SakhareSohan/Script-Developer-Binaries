# 🛠️ Script-Developer-Binaries

Developer productivity scripts for managing projects, logs, and dependencies.

## Scripts

### 1. `c`
Run C or C++ files easily.
```bash
c run <file-name>
```

### 2. `collect-logs`
Collect logs from Applications, Processes, Containers, System, crashes, etc.
Logs are stored under: `$HOME/dev/logs/<category>/<sub>/<timestamp>/`
```bash
collect-logs            # collect everything
collect-logs --containers
collect-logs --apps
collect-logs --deps
collect-logs --crashes
collect-logs --system
collect-logs --scripts
```

### 3. `new-item`
Create new folder structures with detailed overview.
```bash
new-item service user-service
new-item project checkout-portal
```

### 4. `run-deps`
Run dependency containers (Postgres, Redis, RabbitMQ).
```bash
run-deps
```

### 5. `status-deps`
Verify status of dependency containers.
```bash
status-deps
```

### 6. `stop-deps`
Stop dependency containers.
```bash
stop-deps
```

## Note
Containers act as lightweight replacements for Docker. CLI provisioned with Colima.
```bash
colima start
```
