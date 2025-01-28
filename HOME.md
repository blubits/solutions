---
date-created: 2025-01-28
date-updated: 2025-01-28
---
# 📚 Competitive programming editorials

- Library code: `+solutions`

---
## Editorials

```dataviewjs
const statuses = {
  // Content incomplete
  incomplete: '❌ INC',
  // Actively working on it
  working: '📝 WOR',
  // Core content complete. Need problem list + references.
  draft: '📕 DRA',
  // For review and testing (final errors).
  review: '🔍 REV',
  // Complete, can be used.
  complete: '✅ COM',
  // Content complete but currently for updating.
  // updating => review => complete => updating => ...
  updating: '🔄 UPD'
};

var eq = dv
    .pages()
    .filter(b => b.file.name == "EDITORIAL")
    .sort(b => "`" + b.file.frontmatter.platform + "/" + b.file.frontmatter.code + "`")

dv.table(
    ['Code', 'Title', 'Status'],
    eq
      .filter(b => !b.file.path.contains('@old'))
      .map(b => [ 
	      "`" + b.file.frontmatter.platform + "/" + b.file.frontmatter.code + "`",
	      dv.fileLink(
	        b.file.path,
	        false,
	        b.file.frontmatter.title
	      ),
	      statuses[b.file.frontmatter.status]
	  ])
)
```
