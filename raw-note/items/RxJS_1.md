## RxJS youtube tutorials

### [RxJS Quick Start with Practical Examples](https://www.youtube.com/watch?v=2LCo926NFLI), [RxJS Top Ten - Code This, Not That](https://www.youtube.com/watch?v=ewcoEYS85Co), RxJS

---

第一章 - RxJS Quick Start with Practical Examples

第二章 - RxJS Top Ten - Code This, Not That

---

### 第一章 - RxJS Quick Start with Practical Examples

- setup, version 5.4.3
- Observable
  - `create`
  - `fromEvent`
  - `fromPromise`
  - `timer`
  - `interval`
  - `of`
- Hot vs. Cold
  - `publish` + `connect` to be hot, `share` in version 6
- Completion
  - `finally`-> `finalize` in version 6
- Operators
  - `map`
  - `do` -> `tap` in version 6
  - `filter`
  - `first`, `last`
  - `debounce`, `throttle`
  - `scan`
  - `switchMap`
  - `takeUntil`
  - `takeWhile`
  - `zip`
  - `forkJoin`
  - `catch` -> `catchError` in version 6
  - `retry`
  - `multicast`
- Subject
  - `connect`, changed in version 6

---

### 第二章 - RxJS Top Ten - Code This, Not That

- version 6.4.0
- tree shaking `import`
- Observable
  - `create`, `next`, `complete`
  - `of`
  - `from`
  - `fromEvent`
  - `interval`
  - `asyncScheduler`
- Hot vs. Cold
  - Cold, single
  - Hot, multiple
  - `share`, cold to be hot
  - `shareReplay`
- Subjects
  - `new Subject()`
  - `next`
  - `new BehaviorSubject`
- Operators
  - `map`
  - `filter`
  - `scan`
  - `take`
  - `tap`
- Back pressure
  - `debounceTime`
  - `throttleTime`
  - `bufferCount`
- SwitchMap
  - `switchMap`
- Combine
  - `delay`
  - `combineLatest`
  - `merge`
- Errors
  - `catchError`
  - `retry`
- Memory Leaks
  - uncompleted observable
  - unsubscribe subscription
  - `takeWhile`
  - `takeUntil`
